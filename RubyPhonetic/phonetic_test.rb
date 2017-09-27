require_relative 'phonetic'
require 'test/unit'

class PhoneticTest < Test::Unit::TestCase

  def test_rit_to_phonetic
    assert_equal 'ROMEO INDIA TANGO', Phonetic.to_phonetic('RIT')
  end

  def test_line_rit_to_phonetic
    assert_equal 'ROMEO INDIA TANGO', Phonetic.translate('A2P RIT')
  end

  def test_rit_from_phonetic
    assert_equal 'RIT', Phonetic.from_phonetic('Romeo India Tango')
  end
 
  def test_software_to_phonetic
    assert_equal 'SIERRA OSCAR FOXTROT TANGO WHISKEY ALPHA ROMEO ECHO', Phonetic.to_phonetic('Software')
  end

  def test_line_software_from_phonetic
    assert_equal 'SOFTWARE', Phonetic.translate('P2A SIERRA OSCAR FOXTROT TANGO WHISKEY ALPHA ROMEO ECHO')
  end
end
