def valid_parathensis(s: str) -> bool:
    stack = []
    closeToOpen = {')': '(', '}': '{', ']': '['}

    for char in s:
        if char in closeToOpen:
            if stack and stack[-1] == closeToOpen[char]:
                stack.pop()
            else:
                return False
        else:
            stack.append(char)

    return not stack


print(valid_parathensis('()'))  # True
print(valid_parathensis('()[]{}'))  # True

print(valid_parathensis('(]'))  # False
