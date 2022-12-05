# Advent of Code 2022
This repository will be used to store my work for the 2022 installment of Advent of Code. As I write this I think I would like to practice a new language so I've selected C++ since it's quite different from Python and will be useful in future electronics projects. 

-- Please forgive my newbie mistakes --

## Day 01
Just getting my C-legs under me. Compared to Python, C++ isn't quite as straightforward when dealing with strings but `stoi` converting a string to an integer is pretty useful for this task.

## Day 02
A pretty simple Rock/Paper/Scissors problem. I used a class to create a `Weapon` object which I used to track attributes about each side's weapon. the second part changed how the input worked and I attempted to create recursive classes to allow a single class to reference the weapons that it was strong/weak against but I couldn't figure it out and settled on one class for the hero and villain.

## Day 03
Sorting through a bunch of rucksacks (represented as a series of strings) to find various items. This challenge required more string manipulation and introduced me to C++'s `string.find` functionality to find substrings within a string. It's very particular, but once I figured how to generate the right substrings and loops, this kind of just fell into place. It took way longer than it should have. I yearn for Python.

## Day 04
The hardest part about this day was splitting each string into the important number. I built a custom parser but it would be nice if C++ had something like Python's `string.split`. Other than my frustration with strings, this puzzle was straightforward and I only really ran into issues understanding scope, but that is my own comprehension and will come with time.