# Input list
input_list = [1, 2, 3, 4]

# Calculate total product of all elements in the input list
total_product = 1
for num in input_list:
    total_product *= num

# Initialize an empty list to store the output
output_list = []

# Calculate output elements using a single loop
for num in input_list:
    output_list.append(total_product // num)

# Output the result
print(output_list)
