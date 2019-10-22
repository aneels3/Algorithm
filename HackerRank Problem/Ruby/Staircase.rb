#!/bin/ruby

require 'json'
require 'stringio'

# Complete the staircase function below.
def staircase(n)
  spaces=0
  arr = Array.new(n) { |i| Array.new(n) { |j| (i >= j) ? '#' : ' ' } }
  print_matrix(arr.map(&:reverse), spaces)
end

def print_matrix(arr, spaces = 0)
  sep = ' '*(spaces)
  arr.each { |r| puts "#{r.join(sep)}" }
end

n = gets.to_i

staircase n
