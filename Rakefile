OFFSET = 10000
N = 10

desc "generate random tests (no > #{OFFSET})"
task "gen_rand_tests" do
  N.times do |i|
    n = OFFSET + i
    `python gen-rand-graph.py > TEST#{n}`
  end
end

desc "purge random tests"
task "del_rand_tests" do
  N.times do |i|
    n = OFFSET + i
    `rm TEST#{n}`
  end
end

desc "run all tests"
task "run_tests"

NEW_IMPL="tsort"
REF_IMPL="tsort"
def run_test(n)
  f = "TEST#{n}"
  a = `#{NEW_IMPL} #{f} 2>/dev/null`
  b = `#{REF_IMPL} #{f} 2>/dev/null`
  raise "result not same" unless a == b
end

`ls TEST*`.split.each do |t|
  n = t[4..-1].to_i
  test_name = "run#{n}"
  desc "run test no.#{n}"
  task "run#{n}" do
    run_test(n)
  end
  task "run_tests" => test_name
end

task "run_shit_tests" do
  sh "#{NEW_IMPL} --version"
  sh "#{NEW_IMPL} --help"
  sh "#{NEW_IMPL} TEST1" # fail
end
