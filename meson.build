project('flappy', 'cpp',
  version : '0.1',
  default_options: 'defauly_library=static',
  default_options : ['warning_level=3'])

sources = [
  'src/flappy.cpp', 'src/sprite.cpp'
]

includes = [
  include_directories('include')
]

dependencies = [
  dependency('sdl2'),
  dependency('sdl2_image')
]

exe = executable('flappy',
                sources,
                include_directories: includes,
                dependencies: dependencies)

test('basic', exe)
