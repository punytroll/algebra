project(
  'algebra',
  'cpp',
  version: '2.1.1',
  meson_version: '>=0.63.0',
  default_options: [
    'cpp_std=c++20',
    'warning_level=3',
    'werror=true'
  ]
)

algebra_library_dependency = declare_dependency(
  include_directories: [include_directories('include')]
)

test(
  'axis_angle',
  executable(
    'axis_angle',
    sources: ['testing/axis_angle_test.cpp'],
    dependencies: [algebra_library_dependency]
  )
)

test(
  'matrix3f',
  executable(
    'matrix3f_test',
    sources: ['testing/matrix3f_test.cpp'],
    dependencies: [algebra_library_dependency]
  )
)

test(
  'matrix4f',
  executable(
    'matrix4f_test',
    sources: ['testing/matrix4f_test.cpp'],
    dependencies: [algebra_library_dependency]
  )
)

test(
  'quaternion',
  executable(
    'quaternion_test',
    sources: ['testing/quaternion_test.cpp'],
    dependencies: [algebra_library_dependency]
  )
)

test(
  'vector2f',
  executable(
    'vector2f_test',
    sources: ['testing/vector2f_test.cpp'],
    dependencies: [algebra_library_dependency]
  )
)

test(
  'vector3f',
  executable(
    'vector3f_test',
    sources: ['testing/vector3f_test.cpp'],
    dependencies: [algebra_library_dependency]
  )
)

test(
  'vector4d',
  executable(
    'vector4d_test',
    sources: ['testing/vector4d_test.cpp'],
    dependencies: [algebra_library_dependency]
  )
)

test(
  'vector4f',
  executable(
    'vector4f_test',
    sources: ['testing/vector4f_test.cpp'],
    dependencies: [algebra_library_dependency]
  )
)
