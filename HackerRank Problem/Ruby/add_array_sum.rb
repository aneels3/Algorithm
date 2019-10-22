# Simple add numbers of array
# Paste the test function in irb and call sum_array_numbers function

def sum_array_numbers
  puts "Enter array of numbers EG: 1.12 123.12 1 134"
  numbers = gets.chomp
  num = numbers.split(" ")
  sum = num.inject(0) { |sum, i| sum + i.to_f }
  puts "The sum of the numbers is #{sum}"
end

# or run this file as chmod +x add_sum_array.rb and ./add_sum_array.rb
sum_array_numbers
