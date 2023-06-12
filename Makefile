.PHNOY: clean out

#获取code下目录
srcDIRS :=  other output  rely/log rely/time 1path 0menu args
#rely/trie rely/time
srcDIRS := $(addprefix CODE/,${srcDIRS})
buildDIR := Build

#获取code下代码
srcs := $(foreach dir,${srcDIRS},$(shell find ${dir} -name "*.cpp")) CODE/main.cpp 
#放置obj到Build下
objs := $(patsubst %.cpp,%.o,${srcs})
build_objs:= $(foreach obj,${objs},$(addprefix Build/,$(notdir ${obj})))

CXXFLAGS:=-g 


myfind : myfind.conf ${buildDIR} ${build_objs} 
	g++ ${build_objs} CODE/rely/log/liblog.a -o myfind -lboost_filesystem


${build_objs} : ${objs}

${objs} : %.o : %.cpp
	g++ -c $< -o ${buildDIR}/$(notdir $@) ${CXXFLAGS}


${buildDIR}:
	mkdir -p ${buildDIR}

myfind.conf :
	@touch myfind.conf
	@echo "DEFAULT_PATH=." > myfind.conf

clean :
	@rm -r Build || true
	@rm myfind || true
	@rm myfind.conf || true
	@rm *.log

out:
	@echo ${srcs}
	@echo ${objs}



