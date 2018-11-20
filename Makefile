GPP=mingw32-g++
CXXFLAGS= -fshow-column -fshow-column -fno-diagnostics-show-caret  -g2  -O0 "-IC:\Program Files (x86)\ZinjaI\MinGW32-gcc6\wx3\include"  -Wno-unused-local-typedefs -std=gnu++14
LDFLAGS= -static-libstdc++ -static-libgcc "-LC:\Program Files (x86)\ZinjaI\MinGW32-gcc6\wx3\lib\static" -lwxmsw31u_adv -lwxmsw31u_html -lwxmsw31u_core -lwxbase31u -lwxtiff -lwxjpeg -lwxpng -lwxzlib -lkernel32 -luser32 -lgdi32 -lcomdlg32 -lwinspool -lwinmm -lshell32 -lshlwapi -lcomctl32 -lole32 -loleaut32 -luuid -lrpcrt4 -ladvapi32 -lversion -lwsock32 -lwininet  -lsqlite
OBJS=release.w32\Application.o release.w32\V_principal.o release.w32\wxfb_project.o release.w32\utilidades.o release.w32\V_venta.o release.w32\V_retiro.o release.w32\sqlite.o release.w32\V_empleados.o release.w32\V_servicios.o release.w32\V_activo.o release.w32\V_clientes.o release.w32\V_contrato.o 

all: release.w32 release.w32\sunwhas.exe

clean:
	del ${OBJS} release.w32\sunwhas.exe

release.w32\sunwhas.exe: ${OBJS}
	${GPP} ${OBJS} ${LDFLAGS} -o $@

release.w32:
	mkdir release.w32

release.w32\Application.o: Application.cpp Application.h V_principal.h wxfb_project.h utilidades.h sqlite.h
	${GPP} ${CXXFLAGS} -c Application.cpp -o $@

release.w32\V_principal.o: V_principal.cpp V_principal.h wxfb_project.h utilidades.h sqlite.h V_venta.h V_empleados.h V_servicios.h V_activo.h V_retiro.h V_clientes.h V_contrato.h
	${GPP} ${CXXFLAGS} -c V_principal.cpp -o $@

release.w32\wxfb_project.o: wxfb_project.cpp wxfb_project.h
	${GPP} ${CXXFLAGS} -c wxfb_project.cpp -o $@

release.w32\utilidades.o: utilidades.cpp utilidades.h sqlite.h
	${GPP} ${CXXFLAGS} -c utilidades.cpp -o $@

release.w32\V_venta.o: V_venta.cpp V_venta.h wxfb_project.h sqlite.h utilidades.h
	${GPP} ${CXXFLAGS} -c V_venta.cpp -o $@

release.w32\V_retiro.o: V_retiro.cpp V_retiro.h wxfb_project.h sqlite.h utilidades.h
	${GPP} ${CXXFLAGS} -c V_retiro.cpp -o $@

release.w32\sqlite.o: sqlite.cpp sqlite.h utilidades.h
	${GPP} ${CXXFLAGS} -c sqlite.cpp -o $@

release.w32\V_empleados.o: V_empleados.cpp V_empleados.h wxfb_project.h sqlite.h utilidades.h
	${GPP} ${CXXFLAGS} -c V_empleados.cpp -o $@

release.w32\V_servicios.o: V_servicios.cpp V_servicios.h wxfb_project.h sqlite.h utilidades.h
	${GPP} ${CXXFLAGS} -c V_servicios.cpp -o $@

release.w32\V_activo.o: V_activo.cpp V_activo.h wxfb_project.h utilidades.h sqlite.h
	${GPP} ${CXXFLAGS} -c V_activo.cpp -o $@

release.w32\V_clientes.o: V_clientes.cpp V_clientes.h wxfb_project.h sqlite.h utilidades.h
	${GPP} ${CXXFLAGS} -c V_clientes.cpp -o $@

release.w32\V_contrato.o: V_contrato.cpp V_contrato.h wxfb_project.h sqlite.h utilidades.h
	${GPP} ${CXXFLAGS} -c V_contrato.cpp -o $@

