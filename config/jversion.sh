release=$1
arch=$2
link=$3
platform=$4
version=`git describe`
date=`git show --quiet --format=format:%cd --date=short`
branch=`git rev-parse --abbrev-ref HEAD`
cat <<EOL
#define JVERSION "$release/$arch/$platform/$branch/unbox-$version/$link/$date 00:00:00"
EOL
