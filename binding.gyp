{
	"targets": [
		{
			"target_name": "subnet",
			"sources": [
        "src/binding.cc",
        "subnet/ipv4.cc",
        "subnet/cidr.cc",
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "./"
        ],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.12',
        'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES',
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      },
		}
	]
}
