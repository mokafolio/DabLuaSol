project('DabLuaSol', 'cpp', default_options : ['cpp_std=c++14'])

#remove this rather bogus warning
add_project_arguments('-Wno-missing-braces', language: 'cpp')

incDirs = include_directories('.')

install_headers('DabLuaSol/DabLuaSol.hpp', subdir: 'DabLuaSol')

# meseon dependency function to find lua is not very consistent accross platforms yet, so
# we need to do a lot of manual lifting for now
foreach name : ['lua', 'lua5.3', 'lua-5.3', 'lua53']
    luaDep = dependency(name, version: '>=5.3', required: false)
    if luaDep.found()
        break
    endif
endforeach

if not luaDep.found()
    error('Lua could not be found!')
endif

cc = meson.get_compiler('cpp')
if get_option('buildSubmodules') == false
    stickDep = cc.find_library('Stick')
    dabDep = cc.find_library('Dab')
    dabLuaDeps = [stickDep, dependency('threads'), dabDep]
else
    stickProj = subproject('Stick')
    stickLuaProj = subproject('StickLuaSol')
    dabProj = subproject('Dab')
    dabLuaDeps = [stickProj.get_variable('stickDep'), dabProj.get_variable('dabDep'),
    stickLuaProj.get_variable('stickLuaDep')]
endif

if host_machine.system() == 'linux'
    dabLuaDeps += cc.find_library('dl', required : true)
endif

dabLuaDeps += luaDep

dabLua = library('DabLuaSol', 
        'DabLuaSol/DabLuaSol.cpp',
        dependencies: dabLuaDeps, 
        include_directories : incDirs,
        install: true)

dabLuaDep = declare_dependency(link_with : dabLua, 
    dependencies: dabLuaDeps, 
    include_directories: incDirs)

