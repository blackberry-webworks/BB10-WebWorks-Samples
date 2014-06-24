# Push Headless Sample Application

The Push Headless sample push-enabled application demonstrates how to write a BlackBerry 10 WebWorks application that uses a backend headless service to register for push. This allows registration to be done on app install instead of on-first-run. The WebWorks portion will receive any pushes.

Consult the [PushService](http://developer.blackberry.com/html5/apis/beta/blackberry.push.pushservice.html) and [PushPayload](http://developer.blackberry.com/html5/apis/beta/blackberry.push.pushpayload.html) classes from the API reference for useful examples and a full description of how to use the push APIs.

There is also a valuable developer guide on how to write a push-enabled application using BlackBerry WebWorks that you can find [here](https://developer.blackberry.com/html5/documentation/push_service.html).

The developer guide offers the following topics:

1. An overview of push and the Push Service architecture
2. The requirements for creating a full push solution
3. How to download, build and configure the sample application when it's loaded on your BlackBerry 10 device (This is also described below.)
4. Code samples to help you write your own push application using the BlackBerry 10 WebWorks SDK

The sample code for this application is Open Source under the [Apache 2.0 License](http://www.apache.org/licenses/LICENSE-2.0.html).


**Applies To**

* [BlackBerry 10 WebWorks 2.0 SDK](https://developer.blackberry.com/html5/download/sdk)

**Author(s)**
* [James Keshavarzi](https://github.com/jkeshavarzi)

**Based on PushCollector headless sample**

**To contribute code to this repository you must be [signed up as an official contributor](http://blackberry.github.com/howToContribute.html).**

## How to Build

*Note: This sample is configured by default for a BES push. If doing a consumer (public) push, update the ./www/assets/config.ini file and the ops in www/js/index.js.*

To build the Push Headless sample application:

1. webworks create pushHeadless com.example.pushHeadless "Push Headless WebWorks application" *pushHeadlessRepoPath*/www
2. cd pushHeadless
3. webworks plugin add com.blackberry.push
4. webworks plugin add com.blackberry.invoked
5. webworks run

You can now send yourself a push to test that registration was successful.

## Making changes to the native headless portion

If you want to make changes to the native headless portion of the app, you can optionally copy the pushHeadless folder into the root of your app (same location as www). This project can then be imported into Momentics. We suggest you import without selecting the "copy into workspace" option as the MakeFile has been setup to overwrite the headless binary in the WebWorks app. (./www/assets/pushHeadless)

## How to send a push

If doing a BES push, ensure the device has been enterprise activated, has network access (wifi or sim) and your app is installed in the work permiter. You also need to make sure the _sys_use_consumer_push permission is NOT specified in the config.xml. This permission is meant only for public consumer BIS pushes and will cause an error when registering.

If doing a public consumer BIS push, you will need to edit the www/assets/config.ini and uncomment the _sys_use_consumer_push permission in the config.xml.
When editing the config.ini, you will need to update the ApplicationId and PPGUrl fields to match the values you receieved by email when registering for push. Also remember to change the UsingPublicPushProxyGateway parameter to true.

Both types of pushes require the use of a Push Initiator to send the push. Below you will find a list of Push Initiators for public consumer (BIS) pushes.

- [App based BIS Initiator](https://github.com/blackberry/BB10-WebWorks-Samples/tree/master/pushCaptureBasics/pushInitiator)
- [Web based BIS Initiator (Push Service SDK)](https://developer.blackberry.com/services/push/)

You can also optionally create you're own with the [Push Service SDK](https://developer.blackberry.com/services/push).

You'll find all the documentation for the Push Service SDK [here](http://developer.blackberry.com/java/documentation/push_service_sdk.html).
The low-level API reference for the Push Service SDK can be found [here](http://www.blackberry.com/developers/docs/PushServiceSDK1.2/LowLevelAPI).
The high-level API reference for the Push Service SDK can be found [here](http://www.blackberry.com/developers/docs/PushServiceSDK1.2/HighLevelAPI).

If doing a BES push, you can additional try [this](https://github.com/blackberry/BES10-WebWorks/tree/master/SimplePushTest/server) as an initiator.
Simply host the index.html file on a web server and note the below definitions for each field.

- Destination Email: The BES email address associated with the device you are pushing content to (i.e myEmail@myDomain.net).
- BES Address: The BES address (i.e bes123.myDomain.net).
- MDS-CS Listen Port: The Mobile Data Server listen port (Usually 9080).
- Application Listen Port: The appId used when registering for push. This should match what you specified in the config.ini file. For BES pushes, if nothing was specified, one will be randomly generated for you. It's recommended you specifiy an appId (i.e com.example.pushHeadlessAppId).
- Content to Push: The push data to send (i.e Sending some sample test data).

## More Info

* [BlackBerry 10 WebWorks 2.0 SDK](https://developer.blackberry.com/html5/download/)
* [How to write a push-enabled application using BlackBerry WebWorks](https://developer.blackberry.com/html5/apis/beta/blackberry.push.pushservice.html)
* [Push Service SDK Download](https://developer.blackberry.com/services/push)
* [Push Service SDK Development Guide](http://developer.blackberry.com/java/documentation/push_service_sdk.html)
* [Push Service SDK Low-level API Reference](http://www.blackberry.com/developers/docs/PushServiceSDK1.2/LowLevelAPI)
* [Push Service SDK High-level API Reference](http://www.blackberry.com/developers/docs/PushServiceSDK1.2/HighLevelAPI)
* [Push Service Registration Form](https://www.blackberry.com/profile/?eventId=8121)
* [BlackBerry WebWorks Community Forums](http://supportforums.blackberry.com/t5/Web-and-WebWorks-Development/bd-p/browser_dev)
* [BlackBerry Open Source WebWorks Contributions Forums](http://supportforums.blackberry.com/t5/BlackBerry-WebWorks/bd-p/ww_con)

## Contributing Changes

Please see the [README](https://github.com/blackberry/BB10-WebWorks-Samples) of the BB10-WebWorks-Samples repository for instructions on how to add new Samples or make modifications to existing Samples.


## Bug Reporting and Feature Requests

If you find a bug in a Sample, or have an enhancement request, simply file an [Issue](https://github.com/blackberry/BB10-WebWorks-Samples/issues) for the Sample.

## Disclaimer

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
