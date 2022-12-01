import os, shutil

curdir = os.path.curdir
buildir = os.path.join(curdir, 'build')
subprojects = os.path.join(buildir, "subprojects")

shutil.copytree(
    os.path.join(curdir, 'assets'),
    os.path.join(buildir, 'assets'),
    dirs_exist_ok=True
)

if os.name == 'nt':
    shutil.copyfile(
        os.path.join(subprojects, "libjpeg-turbo-2.1.3", "jpeg-8.2.2.dll"),
        os.path.join(buildir, "jpeg-8.2.2.dll")
    )

    shutil.copyfile(
        os.path.join(subprojects, "libpng-1.6.37", "png16-16.dll"),
        os.path.join(buildir, "png16-16.dll")
    )

    shutil.copyfile(
        os.path.join(subprojects, "zlib-1.2.13", "z.dll"),
        os.path.join(buildir, "z.dll")
    )