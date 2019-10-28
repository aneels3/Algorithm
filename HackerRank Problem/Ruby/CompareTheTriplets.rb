#!/bin/ruby

require 'json'
require 'stringio'

# Complete the compareTriplets function below.
def compareTriplets(a, b)
    score_a = 0
    score_b = 0
    
    a.each_with_index do |value_a, index|
        value_b = b[index]
        
        case
        when value_a > value_b
            score_a += 1
        when value_a < value_b
            score_b += 1
        end
    end

    [score_a, score_b]
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

a = gets.rstrip.split.map(&:to_i)

b = gets.rstrip.split.map(&:to_i)

result = compareTriplets a, b

fptr.write result.join " "
fptr.write "\n"

fptr.close()
