blackberry-deploy -uninstallapp -device 169.254.0.1 -password qaqa -package device/invokable.bar
rm -rf device/ simulator/ invokable.zip
zip invokable.zip * -r
~/Documents/ci/packager6/bbwp -d invokable.zip
blackberry-deploy -installapp -launchapp -device 169.254.0.1 -password qaqa -package device/invokable.bar
