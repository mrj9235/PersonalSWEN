# Amino Acids translation
# Ruby Practicum term 2165

# Constants needed for translation
# DO NOT EDIT!
START_CODON = "AUG"
STOP_CODONS = ["UAA","UAG","UGA"]
RNA_TO_AAs = { 'ACU' => 'Thr', 'ACC' => 'Thr', 'ACA' => 'Thr', 'ACG' => 'Thr',
  'GCU' => 'Ala', 'GCC' => 'Ala', 'GCA' => 'Ala', 'GCG' => 'Ala',
  'UAU' => 'Tyr', 'UAC' => 'Tyr', 'CAU' => 'His', 'CAC' => 'His',
  'CAA' => 'Gln', 'CAG' => 'Gln', 'AAU' => 'Asn', 'AAC' => 'Asn',
  'AAA' => 'Lys', 'AAG' => 'Lys', 'GAU' => 'Asp', 'GAC' => 'Asp',
  'GAA' => 'Glu', 'GAG' => 'Glu', 'UGU' => 'Cys', 'UGC' => 'Cys',
  'UGG' => 'Trp', 'CGU' => 'Arg', 'CGC' => 'Arg', 'CGA' => 'Arg',
  'CGG' => 'Arg', 'AGU' => 'Ser', 'AGC' => 'Ser', 'AGA' => 'Arg',
  'AGG' => 'Arg', 'GGU' => 'Gly', 'GGC' => 'Gly', 'GGA' => 'Gly',
  'GGG' => 'Gly', 'AUG' => 'Met', 'UUU' => 'Phe', 'UUC' => 'Phe',
  'UUA' => 'Leu', 'UUG' => 'Leu', 'CUC' => 'Leu', 'CUG' => 'Leu',
  'AUU' => 'Ile', 'AUC' => 'Ile', 'AUA' => 'Ile', 'GUU' => 'Val',
  'GUC' => 'Val', 'GUA' => 'Val', 'GUG' => 'Val', 'UCU' => 'Ser',
  'UCC' => 'Ser', 'UCA' => 'Ser', 'UCG' => 'Ser', 'CCU' => 'Pro',
  'CCC' => 'Pro', 'CCA' => 'Pro', 'CCG' => 'Pro', }

  # Given: a string containing DNA characters
  # Return: a string of capitalized DNA letters only
  #
  # DNA Nucleotides can be A,T,G, or C 
  #
def parse_dna(str)
  nucleo = ["A", "C", "G", "T"]
  dna = ""
  if str.empty?
    return dna
  end
  str.each_char{|c|
    c.upcase!
    if nucleo.include? c
      dna = dna + c
    end
  }
  return dna
end

# Given: a string of DNA characters
# Return: a string of RNA
#
# DNA Nucleotides can be A,T,G, or C 
# RNA Nucleotides can be A,U,G, or C 
# Transcription replaces T with U.
#
def transcribe(dna)
  if dna.include?("T")
    dna.gsub!("T", "U")
  end
  return dna
end

# Given: a string of RNA characters
# Return: an array of codons
#
# Codons are groups of three nucleotides at a time.
# Nucleotides can be A,U,G, or C
# Any leftover nucleotides that don't fit into  codon are ignored
# Ignore all other characters
#  (e.g. UUUU parses to ['UUU'])
#
# Hint: String's each_char may be a helpful method
# Hint: using split is NOT recommended
# Hint: complex regular expressions are also not a good idea
#
def parse_codons(str)
  codon = ""
  codons = []
  if str.empty?
    return []
  end
  codons = str.split(/..../)
  if codons.length != 0
    codon = codons.fetch(codons.length-1)
    if codon.length < 3
      codons.pop
    end
  end
##  str.each_char{|c|
##    if str.length == 3
##      codons.push(codon)
##      codon = ""
##    else
##      codon = codon + c
##    end
##  }
  return codons
end

# Given:  an array of capitalized codons
# Return: a string of space-delimited Amino acids
#
# Translation doesn't start until the START_CODON is reached
# Translation stops when one of the STOP_CODONs is reached
# Translation stops when one of the STOP_CODONs is reached,
#   but only after translation started
# We are not handling any start-stop-start scenarios.
#
def translate(codons)
  i = 0
  amino = ""
  if codons.empty?
    return ""
  end
  until codons.fetch(i).eql?(START_CODON) || i == codons.length - 1 do
    i += 1
  end
  if codons.fetch(i).eql?(START_CODON)
    amino = amino + RNA_TO_AAs.fetch(codons.fetch(i)) + " "
    i += 1
  end
  while i < codons.length do
    if STOP_CODONS.include? codons.fetch(i)
      break;
    end
    amino = amino+  RNA_TO_AAs.fetch(codons.fetch(i)) + " "
    i += 1
  end
  return amino
end
