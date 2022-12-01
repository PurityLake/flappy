project('flappy', 'cpp',
  version : '0.1',
  default_options: 'default_library=static',
  default_options : ['warning_level=3'])

sources = [
  'src/main.cpp', 'src/sprite.cpp'
]

includes = [
  include_directories('include')
]

dependencies = [
  dependency('sdl2', static: true),
  dependency('sdl2_image', static: true),
  dependency('libpng', static: true)
]

exe = executable('flappy',
                sources,
                win_subsystem: 'windows',
                include_directories: includes,
                dependencies: dependencies)

test('basic', exe)
