#! /usr/bin/env tclsh

puts hello
puts {Hello World}

set hello {Hello World}
set greeting $hello
puts $hello
puts $greeting

set hello_len [string length $hello]
puts [string length {foo bar}]
puts $hello_len

puts [expr 2*2]
puts [expr 2*2+2]
puts [expr 2*(2+2)]
puts [expr {2*(2+2)}]; #more effective

puts "$hello contains $hello_len characters" 
puts {$hello is variable}
puts {[expr {2+2}]}
puts "foobar contains [string length foobar] letters"
puts "$hello and foobar contain [expr {[string length foobar] + $hello_len}] characters";

puts [format "%s \t %i" $hello $hello_len]
puts [format {%s \t %i} $hello $hello_len]

proc Greeting {first_name second_name} {
	puts "hello $first_name $second_name!"
}

Greeting Super Sonic

set a 10
while {$a != 0} {
	puts $a
	incr a -1
}
