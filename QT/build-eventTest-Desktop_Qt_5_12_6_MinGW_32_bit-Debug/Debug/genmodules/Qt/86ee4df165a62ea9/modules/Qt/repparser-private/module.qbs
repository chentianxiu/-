import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "RepParser"
    Depends { name: "Qt"; submodules: ["repparser"]}

    architectures: ["x86"]
    targetPlatform: "windows"
    hasLibrary: false
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: undefined
    libNameForLinkerRelease: undefined
    libFilePathDebug: undefined
    libFilePathRelease: undefined
    pluginTypes: []
    moduleConfig: []
    cpp.defines: []
    cpp.includePaths: ["D:/QT/5.12.6/mingw73_32/include/QtRepParser/5.12.6","D:/QT/5.12.6/mingw73_32/include/QtRepParser/5.12.6/QtRepParser"]
    cpp.libraryPaths: []
    
}
