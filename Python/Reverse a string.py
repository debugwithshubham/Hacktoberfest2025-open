def reverse_string(s):
  """
  Reverses a given string.

  Args:
    s: The input string to reverse.

  Returns:
    The reversed string.
  """
  # Python's extended slice syntax [::-1] is a concise
  # and efficient way to reverse a sequence.
  return s[::-1]

# --- Example Usage ---
original_string = "Hello Python"
reversed_str = reverse_string(original_string)

print(f"Original: {original_string}")
print(f"Reversed: {reversed_str}")

# --- Test with another string ---
another_string = "madam"
print(f"\nOriginal: {another_string}")
print(f"Reversed: {reverse_string(another_string)}")
