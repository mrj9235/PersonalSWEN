# Convert to/from phonetic alphabet
# YOUR NAME HERE

class Phonetic

  Letters = [
             ['A', 'ALPHA'],
             ['B', 'BRAVO'],
             ['C', 'CHARLIE'],
             ['D', 'DELTA'],
             ['E', 'ECHO'],
             ['F', 'FOXTROT'],
             ['G', 'GOLF'],
             ['H', 'HOTEL'],
             ['I', 'INDIA'],
             ['J', 'JULIET'],
             ['K', 'KILO'],
             ['L', 'LIMA'],
             ['M', 'MIKE'],
             ['N', 'NOVEMBER'],
             ['O', 'OSCAR'],
             ['P', 'PAPA'],
             ['Q', 'QUEBEC'],
             ['R', 'ROMEO'],
             ['S', 'SIERRA'],
             ['T', 'TANGO'],
             ['U', 'UNIFORM'],
             ['V', 'VICTOR'],
             ['W', 'WHISKEY'],
             ['X', 'XRAY'],
             ['Y', 'YANKEE'],
             ['Z', 'ZULU'],
             ]

  # Translate a word to its phonetic alphabet equivalent
  def self.to_phonetic(word)
    word.upcase!
    str = ""
    word.each_char do |c|
      i = 0
      until Letters[i].include? c
        i += 1
      end
      str += Letters[i][1] + " "
    end
    return str.chop
  end

  # Translate a sequence of phonetic alphabet code words 
  # to their alphabetic equivalent
  def self.from_phonetic(str)
    str.upcase!
    words = str.split(' ')
    alpha = ""
    words.each do |word|
      i = 0
      until Letters[i].include? word
        i += 1
      end
      alpha += Letters[i][0]
    end
    return alpha
  end

  # If the line starts with A2P, call to_phonetic on the rest of the substring
  # If the line starts with P2A, call from_phonetic on the rest of the substring
  # Otherwise, return nothing.
  def self.translate(line)
    if line.start_with? 'P2A'
      final = from_phonetic(line[4..line.length])
    elsif line.start_with? 'A2P'
      final = to_phonetic(line[4..line.length])
    else
      final = nil
    end
    return final
  end

end

# This is ruby idiom that allows us to use both unit testing and command line processing
# This gets run with ruby phonetic.rb
# Does not get run when we use unit testing, e.g. ruby phonetic_test.rb
if __FILE__ == $PROGRAM_NAME
  $stdin.each do |line|
    puts Phonetic.translate(line)
  end
end
