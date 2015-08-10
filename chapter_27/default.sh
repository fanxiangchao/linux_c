#!/bin/sh
#default.sh

echo linux $version
echo "set default-value"
echo linux ${version:-2.6.12}
echo the value is : $version
version="new version"
echo linux ${version:-2.6.12}