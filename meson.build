project(
  'algebra',
  'cpp',
  version: '26.11.1',
  meson_version: '>=1.12.0',
  default_options: {
    'cpp_std': 'c++26',
    'warning_level': '3',
  },
)

algebra_library_dependency = declare_dependency(
  include_directories: [include_directories('include')]
)

meson.override_dependency(
  'algebra',
  algebra_library_dependency,
)

enable_tests = get_option('tests').enable_auto_if(meson.is_subproject() == false).enabled()
summary({'run tests': enable_tests}, bool_yn: true, section: 'Features')
if enable_tests == true
  test(
    'axis_angle',
    executable(
      'axis_angle',
      build_by_default: false,
      dependencies: [algebra_library_dependency],
      sources: ['testing/axis_angle_test.cpp'],
    )
  )

  test(
    'matrix3f',
    executable(
      'matrix3f_test',
      build_by_default: false,
      dependencies: [algebra_library_dependency],
      sources: ['testing/matrix3f_test.cpp'],
    )
  )

  test(
    'matrix4f',
    executable(
      'matrix4f_test',
      build_by_default: false,
      dependencies: [algebra_library_dependency],
      sources: ['testing/matrix4f_test.cpp'],
    )
  )

  test(
    'quaternion',
    executable(
      'quaternion_test',
      build_by_default: false,
      dependencies: [algebra_library_dependency],
      sources: ['testing/quaternion_test.cpp'],
    )
  )

  test(
    'vector2f',
    executable(
      'vector2f_test',
      build_by_default: false,
      dependencies: [algebra_library_dependency],
      sources: ['testing/vector2f_test.cpp'],
    )
  )

  test(
    'vector3f',
    executable(
      'vector3f_test',
      build_by_default: false,
      dependencies: [algebra_library_dependency],
      sources: ['testing/vector3f_test.cpp'],
    )
  )

  test(
    'vector4d',
    executable(
      'vector4d_test',
      build_by_default: false,
      dependencies: [algebra_library_dependency],
      sources: ['testing/vector4d_test.cpp'],
    )
  )

  test(
    'vector4f',
    executable(
      'vector4f_test',
      build_by_default: false,
      dependencies: [algebra_library_dependency],
      sources: ['testing/vector4f_test.cpp'],
    )
  )
endif
