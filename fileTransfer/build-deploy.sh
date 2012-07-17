blackberry-deploy -uninstallapp -device 169.254.0.1 -password qaqa -package device/filetransfer.bar
rm -rf device/ simulator/ filetransfer.zip
zip filetransfer.zip * -r
~/Documents/ci/packager5/bbwp -d filetransfer.zip
blackberry-deploy -installapp -launchapp -device 169.254.0.1 -password qaqa -package device/filetransfer.bar
