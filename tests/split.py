result = []
command = "gyatt    notepad.exe hello.txt"

word = ""
for ch in command:
    if ch != " ":
        word += ch
    elif word != '':
        result.append(word)
        word = ""

if word:
    result.append(word)

print(result)