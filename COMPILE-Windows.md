Install Visual Studio 2022 with C++ compiler
Install Qt libraries, cmake, ninja from online installer at https://www.qt.io/download-qt-installer-oss

D:
cd D:\dev\OSS
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg.exe integrate install (as admin)
.\vcpkg.exe install arrow:x64-windows-static-md

set Qt5_DIR=C:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5

D:
cd D:\dev\OSS\PlotJuggler
D:\dev\OSS\vcpkg\vcpkg.exe install --triplet x64-windows
set CMAKE_TOOLCHAIN=D:/dev/OSS/vcpkg/scripts/buildsystems/vcpkg.cmake
C:\Qt\Tools\CMake_64\bin\cmake.exe -G "Visual Studio 17" -S . -B build -DCMAKE_TOOLCHAIN_FILE=%CMAKE_TOOLCHAIN% -DCMAKE_INSTALL_PREFIX=%cd%/install -DCMAKE_BUILD_TYPE=RelWithDebInfo

C:\Qt\Tools\CMake_64\bin\cmake.exe --build build --config RelWithDebInfo --target install

# copy files from D:\dev\OSS\PlotJuggler\install\bin to D:\dev\OSS\PlotJuggler\installer\io.plotjuggler.application\data
# along with brotlicommon.dll, brotlienc.dll, brotlidec.dll, bz2.dll, lz4.dll, snappy.dll, zlib1.dll, zstd.dll, libcrypto-3-x64.dll

C:\Qt\5.15.2\msvc2019_64\bin\windeployqt.exe --release installer\io.plotjuggler.application\data\plotjuggler.exe
