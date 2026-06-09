%pip install ddgs
from duckduckgo_search import DDGS

def search(query, max_results=5):
    with DDGS() as ddgs:
        results = ddgs.text(query, max_results=max_results)
        return [r['title'] for r in results]

def main():
    print("Search Bot  |  type 'quit' to exit\n")
    while True:
        query = input("You: ").strip()
        if not query:
            continue
        if query.lower() in ('quit', 'exit', 'q'):
            print("Bye!")
            break
        titles = search(query)
        if titles:
            print("\nTop results:")
            for i, title in enumerate(titles, 1):
                print(f"  {i}. {title}")
        else:
            print("  No results found.")
        print()

if __name__ == "__main__":
    main()
