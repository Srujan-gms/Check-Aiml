def negation(literal):
    if literal.startswith("~"):
        return literal[1:]
    return "~" + literal

def is_tautology(clause):
    return any(negation(lit) in clause for lit in clause)

def resolve(clause1, clause2):
    resolvents = []
    for literal1 in clause1:
        for literal2 in clause2:
            if literal1 == negation(literal2):
                resolvent = tuple(sorted(set(
                    lit for lit in (clause1 + clause2)
                    if lit != literal1 and lit != literal2
                )))
                if not is_tautology(resolvent) and resolvent not in resolvents:
                    resolvents.append(resolvent)
    return resolvents

def resolve_all(clauses):
    new_clauses = set()
    for i, clause1 in enumerate(clauses):
        for clause2 in clauses[i+1:]:
            for r in resolve(clause1, clause2):
                new_clauses.add(r)
    return new_clauses

def resolution(kb):
    clauses = []
    for clause in kb:
        cleaned = clause.replace("(", "").replace(")", "")
        literals = tuple(sorted([lit.strip() for lit in cleaned.split("||")]))
        if not is_tautology(literals):
            clauses.append(literals)

    MAX_CLAUSES = 200

    while True:
        new_clauses = resolve_all(clauses)

        if () in new_clauses:
            return "Unsatisfiable"

        if new_clauses.issubset(set(clauses)):
            return "Satisfiable"

        for nc in new_clauses:
            if nc not in clauses:
                clauses.append(nc)

        if len(clauses) > MAX_CLAUSES:
            return "Satisfiable (depth limit reached)"

knowledge_base = [
    "(P || Q || ~R)",
    "(~P || R)",
    "(~Q || R)",
    "(~R || ~P || Q)"
]

result = resolution(knowledge_base)
print(f"Knowledge Base is: {result}")