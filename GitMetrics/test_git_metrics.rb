require_relative 'git_metrics'
require 'test/unit'

class TestGitMetrics < Test::Unit::TestCase

  def test_commit_example
  	assert_equal 2, num_commits(["commit abc", "commit 123"]), "Should have counted two commits"
  end

  def test_dates_with_three_days
  	exp = [ "Date:  Sun Jan 26 21:25:22 2014 -0600", \
  			"Date:  Sun Jan 23 21:25:22 2014 -0600", \
  			"Date:  Sun Jan 25 21:25:22 2014 -0600"]
    assert_equal 4, days_of_development(exp), "Should have been a 4 days difference"
  end

  #Add more tests here
  def test_commit_again
	ex = ["Author: Meghan Johnson <email@email.com>"]
	assert_equal 0, num_commits(ex), "Should have counted zero commits"
  end

  def test_dates_with_zero_days
	exp = ["commit 1fg123", "Author: Author"]
	assert_equal 0, days_of_development(exp), "Should have been a difference of 0 days"
  end

  def test_authors_no_repeats
	exp = ["Author: Brad <email@email.com>", "Author: Cheryl <cheryl@email.com>", "Author: Maxwell <Maxwell@email.com>"]
	assert_equal 3, num_developers(exp), "Should have been a total of three developers"
  end

  def test_authors_with_repeats
	exp = ["Author: Brad <email@email.com>", "Author: Cheryl <cheryl@email.com>", "Author: Cheryl <cheryl@email.com>","Author: Cheryl <cheryl@email.com>", "Author: Cheryl <cheryl@email.com>", "Author: Jonas <jonas@brothers.com>", 
		"Author: Jim <jim@jim.jim>"]
	assert_equal 4, num_developers(exp), "Should have been a total of four different developers"
  end
end
