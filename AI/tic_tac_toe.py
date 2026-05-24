# Initialize the board with empty spaces
theBoard = {
    'top-L': ' ', 'top-M': ' ', 'top-R': ' ',
    'mid-L': ' ', 'mid-M': ' ', 'mid-R': ' ',
    'low-L': ' ', 'low-M': ' ', 'low-R': ' '
}

def printBoard(board):
    print(board['top-L'] + '|' + board['top-M'] + '|' + board['top-R'])
    print('-+-+-')
    print(board['mid-L'] + '|' + board['mid-M'] + '|' + board['mid-R'])
    print('-+-+-')
    print(board['low-L'] + '|' + board['low-M'] + '|' + board['low-R'])

turn = 'X'
for i in range(9):
    printBoard(theBoard)
    print('Turn for ' + turn + '. Move on which space?')
    
    # Loop until the player enters a valid, empty space
    while True:
        move = input()
        if move in theBoard:
            if theBoard[move] == ' ':
                break  # Valid move, exit the input loop
            else:
                print('That space is already taken! Choose another:')
        else:
            print('Invalid space! Use top-L, mid-M, low-R, etc. Try again:')
            
    theBoard[move] = turn
    
    # Alternate turns
    if turn == 'X':
        turn = 'O'
    else:
        turn = 'X'

# Print final board state
printBoard(theBoard)
