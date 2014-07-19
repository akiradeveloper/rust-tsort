require "benchmark"

OFFSET = 10000
N = 10

$failures = []
$ratios = []
$max_ratio = 0
$min_ratio = Float::INFINITY

desc "generate random tests (no > #{OFFSET})"
task "gen_rand_tests" do
  N.times do |i|
    n = OFFSET + i
    `python gen-rand-graph.py > TEST#{n}`
  end
  N.times do |i|
    n = OFFSET + OFFSET + i
    `python gen-rand-dag.py > TEST#{n}`
  end
end

desc "purge random tests"
task "del_rand_tests" do
  N.times do |i|
    n = OFFSET + i
    `rm TEST#{n}`
  end
  N.times do |i|
    n = OFFSET + OFFSET + i
    `rm TEST#{n}`
  end
end

class Array
  def average
    inject(0.0) { |sum, i| sum += i } / size
  end

  def variance
    ave = average
    inject(0.0) { |sum, i| sum += (i - ave) ** 2 } / size
  end

  def standard_deviation
    Math::sqrt variance
  end
end

desc "run all tests"
task "run_tests" do
  print "failures=#{$failures}\nmax ratio=#{$max_ratio}\nmin ratio=#{$min_ratio}\nave ratio=#{$ratios.average}\nstd dev=#{$ratios.standard_deviation}\n"
end

# NEW_IMPL="~/coreutils/build/tsort"
NEW_IMPL="tsort"
REF_IMPL="tsort"
def run_test(n)
  f = "TEST#{n} "
  print f
  a = ""; b = ""
  t_new = Benchmark.realtime { a = `#{NEW_IMPL} #{f} 2>/dev/null` }
  t_ref = Benchmark.realtime { b = `#{REF_IMPL} #{f} 2>/dev/null` }
  success = a == b

  acyclic = `#{REF_IMPL} #{f} 1>/dev/null 2>&1; echo $?`.to_i == 0
  print "result: #{success ? "OK" : "NG"}, acyclic:#{acyclic}, time: t_new/t_ref=#{t_new}/#{t_ref}\n"

  $failures << n unless success
  ratio = t_new / t_ref
  $ratios << ratio
  $max_ratio = [ratio, $max_ratio].max
  $min_ratio = [ratio, $min_ratio].min
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
