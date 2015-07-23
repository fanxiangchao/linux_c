all:
	ls
	./hello
.PHONY:all

exec:
	cd /home
	pwd
.PHONY:exec

exec1:
	cd /home ; pwd
.PHONY:exec1

var1 =
var2 = hello
condition:
ifdef $(var1)
	echo "var1 is defined"
else
	echo "var1 is undefined"
endif
ifeq ($(var1),$(var2))
	echo "they are equal"
else
	echo "they are not equal"
endif
.PHONY:condition

func:
result=$(subst a,A,how are you, China?)
replace = $(patsubst %.mk,%.o, mkefile.mk.mk a.mk)
func:
	echo -n "the result is :"
	echo $(result)
	echo -n "the replace is :"
	echo $(replace)
.PHONY:func


#strip function
str = "    hello world   "
result = $(strip $(str))
strip_func:
	echo -n "[strip] the result is : "
	echo $(result)
.PHONY:strip_func

#find function
result = $(findstring he,hello)
findstr_func:
	echo -n "[findstring] the result is : "
	echo $(result)
.PHONY:findstr_func

#filter function
sources := a.c b.c c.c d.h e f
result = $(filter %.c %.h,$(sources))
filter_func:
	echo -n "[filter] the result is : "
	echo $(result)
.PHONY:filter_func

#filter out function
result = $(filter-out %.c %.h,$(sources))
filterout_func:
	echo -n "[filter-out] the result is : "
	echo $(result)
.PHONY:filterout_func

#sort function
result = $(sort hello world china hello world china)
sort_func:
	echo -n "[sort] the result is : "
	echo $(result)
.PHONY:sort_func

#word function
result1 = $(word 2,hello world china)
result2 = $(word 5,hello world china)
word_func:
	echo -n "[word] the result1 is : "
	echo $(result1)
	echo -n "[word] the result2 is : "
	echo $(result2)
.PHONY:word_func


#wordlist function
result1 = $(wordlist 1,2,hello world china)
result2 = $(wordlist 3,2,hello world china)
result3 = $(wordlist 2,5,hello world china)
wordlist_func:
	echo -n "[wordlist] the result1 is : "
	echo $(result1)
	echo -n "[wordlist] the result2 is : "
	echo $(result2)
	echo -n "[wordlist] the result3 is : "
	echo $(result3)
.PHONY:wordlist_func

#words function
result = $(words hello      world     china)
words_func:
	echo -n "[words] the result is : "
	echo $(result)
.PHONY:words_func

#firstword function
result = $(firstword hello world china)
firstword_func:
	echo -n "[firstword] the result is : "
	echo $(result)
.PHONY:firstword_func

#dir function
result = $(dir test.c /home/admin/test.c)
dir_func:
	echo -n "[dir] the result is : "
	echo $(result)
.PHONY:dir_func

#notdir function
result = $(notdir test.c /home/admin/test.c)
notdir_func:
	echo -n "[notdir] the result is : "
	echo $(result)
.PHONY:notdir_func

#suffix function
result = $(suffix test.txt test.c file test.mp4 test.rmvb)
suffix_func:
	echo -n "[suffix] the result is : "
	echo $(result)
.PHONY:suffix_func

#basename function
result = $(basename test.txt /home/admin/test.c /home/admin file)
basename_func:
	echo -n "[basename] the result is : "
	echo $(result)
.PHONY:basename_func

#addsuffix function
result = $(addsuffix .c,a b c)
addsuffix_func:
	echo -n "[addsuffix] the result is : "
	echo $(result)
.PHONY:addsuffix_func

#addprefix function
result = $(addprefix /home/admin, test1.c test2.txt test3.mp4)
addprefix_fun:
	echo -n "[addprefix] the result is : "
	echo $(result)
.PHONY:addprefix_func

#join function
result1 = $(join /home/ /home/admin/, test1.c test2.txt test3.mp4)
result2 = $(join /home/ /home/admin/ /home/admin/user/, test1.c test2.txt test3.mp4)
join_func:
	echo -n "[join] the result1 is : "
	echo $(result1)
	echo -n "[join] the result2 is : "
	echo $(result2)
.PHONY:join_func

#foreach function
names := a b c d e f g,h
files :=  $(foreach n,$(names),$(n).c)
foreach_func:
	echo -n "[foreach] the result is : "
	echo $(files)
.PHONY:foreach_func

#if function
a := 1
b := 1
result := $(if ifeq($a,$b), $a = 10, $b = 10)
if_func:
	echo -n "[if] the result is : "
	echo $(result)
.PHONY:if_func

#call function
add = $(1) + $(2)
result := $(call add,1,2)
call_func:
	echo -n "[call] the result is : "
	echo $(result)
.PHONY:call_func

#origin function
result1 = $(origin name)  #name must defined in command line
result2 = $(origin result)
result3 = $(origin PATH)
result4 = $(origin notdefined)
origin_func:
	echo -n "[origin] the result is : "
	echo $(result1) $(result2) $(result3) $(result4)
.PHONY:origin_func

#shell function
files := $(shell ls)
shell_func:
	echo -n "[shell] the result is : "
	echo $(files)
.PHONY:shell_func
