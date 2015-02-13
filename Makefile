OBJECTS := `find */*.cpp | sed -r "s/^(\.git|bin|obj|in|out|\`find * -name "main.cpp" | sed -r 's/\/[^\/]+$$//' | xargs echo | tr ' ' '|'\`).*$$//" | grep -E ".+" | sed -r 's/cpp$$/o/' | sed -r 's/^/obj\//'`
PROJECTS:= `find * -name "main.cpp" | sed -r 's/\/[^\/]+$$//'`
CXXFLAGS:= -std=c++11 -fopenmp -pipe -w -O2 -Wall -W
LIBS	:=

all:
	for project in $(PROJECTS); do make ~$$project; done

obj/%.o: %.cpp
	@echo "Compilando dependencia: '$<'..."
	@mkdir -p $(@D)
	@$(CXX) -c $(CXXFLAGS) -I. $< -o $@ $(LIBS)

~%: %
	@echo "Construyendo dependencias para '$<'..."
	@for object in $(OBJECTS) `find $</*.cpp | sed -r 's/cpp$$/o/' | sed -r 's/^/obj\//'`; do make --silent $$object; done
	@echo "Construyendo ejecutable de '$<'..."
	@$(CXX) $(CXXFLAGS) $(OBJECTS) `find obj/$</*.o` -I. -o bin/$< $(LIBS)

clean:
	rm -f bin/* `find * | grep -E "\.o$$"`

.SILENT: $(PROJECTS)

install: FORCE

uninstall: FORCE

FORCE:
