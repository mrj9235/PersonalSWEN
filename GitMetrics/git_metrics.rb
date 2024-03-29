# Script that obtains various git metrics from a basic git log file
require 'set'
require 'date'

# Given an array of git log lines, count the number of commits in the log
def num_commits(lines)
        i = 0
	lines.each{|line| 
		if line.include? "commit"
			i += 1
		end
	}
	return i
end

# Given an array of git log lines, count the number of different authors
#   (Don't double-count!)
# You may assume that emails make a developer unique, that is, if a developer
# has two different emails they are counted as two different people.
def num_developers(lines)
	emails = []
	lines.each{|line|
		if line.include? "Author:"
			words = line.split(" ")
			words.each{|word|
				if word.include?('@')
					emails += [word] if !emails.include? (word)
				end
			}
		end
	}
	return emails.length
			
end

# Given an array of Git log lines, compute the number of days this was in development
# Note: you cannot assume any order of commits (e.g. you cannot assume that the newest commit is first).
def days_of_development(lines)
	dates = []
	lines.each{|line|
		if line.start_with? "Date:"
			dates += [Date.parse(line)]
		end
	}
	if dates.length != 0
		dateMax = dates.max()
		dateMin = dates.min()
		return (dateMax - dateMin + 1).to_i
	end
	return 0
end

# This is a ruby idiom that allows us to use both unit testing and command line processing
# Does not get run when we use unit testing, e.g. ruby test_git_metrics.rb
# These commands will invoke this code with our test data: 
#    ruby git_metrics.rb < ruby-progressbar-short.txt
#    ruby git_metrics.rb < ruby-progressbar-full.txt
if __FILE__ == $PROGRAM_NAME
  lines = []
  $stdin.each { |line| lines << line }
  puts "Number of commits: #{num_commits lines}"
  puts "Number of developers: #{num_developers lines}"
  puts "Number of days in development: #{days_of_development lines}"
end

