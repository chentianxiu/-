import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Gamepad"
    Depends { name: "Qt"; submodules: ["core-private","gamepad"]}

    architectures: ["x86_64"]
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
    cpp.includePaths: ["D:/QT/5.12.6/msvc2015_64/include/QtGamepad/5.12.6","D:/QT/5.12.6/msvc2015_64/include/QtGamepad/5.12.6/QtGamepad"]
    cpp.libraryPaths: []
    
}