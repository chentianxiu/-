import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "3DQuickRender"
    Depends { name: "Qt"; submodules: ["core-private","qml-private","3dquick-private","3dcore-private","3drender-private","3dquickrender"]}

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
    cpp.includePaths: ["D:/QT/5.12.6/mingw73_32/include/Qt3DQuickRender/5.12.6","D:/QT/5.12.6/mingw73_32/include/Qt3DQuickRender/5.12.6/Qt3DQuickRender"]
    cpp.libraryPaths: []
    
}