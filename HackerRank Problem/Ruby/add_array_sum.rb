# Simple add numbers of array
# Paste the test function in irb and call sum_array_numbers function

def simpleArraySum(numbers)
  num = numbers.split(" ")
  num.inject(0) { |sum, i| sum + i.to_i }
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')
ar_count = gets.to_i
ar = gets.rstrip
result = simpleArraySum(ar)
fptr.write result
fptr.write "\n"
fptr.close()
