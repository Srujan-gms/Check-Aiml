class BackwardChaining:
	def __init__ (self, rules, facts):
		self.rules=rules
		self.facts= set(facts)

	def is_fact(self, fact):
		if fact in self.facts:
			return True
		for antecedent, consequent in self.rules:
			if consequent == fact: 
				if all(self.is_fact(ant) for ant in antecedent):
					self.facts.add(fact)
					return True
		return False
# Define rules as (antecedent, consequent) pairs 
rules= [
({"has_fur(tiger)"}, "mammal(tiger)"),
({"has_feathers(penguin)", "lays_eggs(penguin)"}, "bird(penguin)"),
 ({"lays_eggs(sparrow)", "has_feathers(sparrow)"}, "bird(sparrow)"),
  ({"has_fur(cat)"}, "mammal(cat)")
]

#Initial facts
initial_facts = {"has_fur(tiger)", "has_feathers(penguin)", "lays_eggs(penguin)", "lays_eggs(sparrow)", "has_fur(cat)"}

#Goals
goals = ["mammal(tiger)", "bird(penguin)", "bird(sparrow)", "mammal(cat)"]

bc=BackwardChaining(rules, initial_facts)

for goal in goals:
	if bc.is_fact(goal):
		print (f"Goal {goal} can be derived from the facts.")
	else:
		print(f"Goal {goal} cannot be derived from the facts.")