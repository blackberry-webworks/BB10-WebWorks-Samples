# Push Headless Sample Application

The Push Headless sample push-enabled application demonstrates how to write a BlackBerry 10 WebWorks application that uses a backend headless service to register for push. This allows registration to be done on app install instead of on-first-run. The webworks portion will receive any pushes.

Consult the [PushService](http://developer.blackberry.com/html5/apis/beta/blackberry.push.pushservice.html) and [PushPayload](http://developer.blackberry.com/html5/apis/beta/blackberry.push.pushpayload.html) classes from the API reference for useful examples and a full description of how to use the
push APIs.

There is also a valuable developer guide on how to write a push-enabled application using BlackBerry WebWorks that you can find [here](https://developer.blackberry.com/html5/documentation/push_service.html).

The developer guide offers the following topics:

1. An overview of push and the Push Service architecture
2. The requirements for creating a full push solution
3. How to download, build, and configure the sample application when it's loaded on your BlackBerry 10 device (This is also described below.)
4. Code samples to help you write your own push application using the BlackBerry 10 WebWorks SDK

The sample code for this application is Open Source under the [Apache 2.0 License](http://www.apache.org/licenses/LICENSE-2.0.html).


**Applies To**

* [BlackBerry 10 WebWorks 2.0 SDK](https://developer.blackberry.com/html5/download/sdk)

**Port to WebWorks 2.0**
* [Luca Sale](https://github.com/lsale)

**Author(s)**
* [James Keshavarzi](https://github.com/jkeshavarzi)

**Based on PushCollector headless sample**

**To contribute code to this repository you must be [signed up as an official contributor](http://blackberry.github.com/howToContribute.html).**


## How to Build

To build the Push Headless sample application:

1. webworks create pushHeadless com.example.pushCollectorUI "Headless Push WebWorks Application" ./*pushHeadlessRepo*/www
2. cd pushHeadless
3. webworks plugin add com.blackberry.push
4. webworks plugin add com.blackberry.invoked
5. webworks run

You can now send yourself a push to test that registration was successful.

*if using BES for push, ensure you are on the work perimeter*

## Making changes to the native headless portion

If you want to make changes to the native headless portion of the app, you can optionally copy the pushCollectorHeadless folder into the root of your app (same location as www). This project can then be imported into Momentics. We suggest you import without selecting the "copy into workspace" option as the MakeFile has been setup to overwrite the output binary in the WebWorks app. (./www/assets/pushCollectorHeadless)

## How to send a push

In order to be able to send pushes to the Push Capture sample app, you will need to write a server-side push application (called a Push Initiator) to send out pushes with.
Luckily, this is fairly easy to do using the Push Service SDK available [here](https://developer.blackberry.com/services/push).

You'll find all the documentation for the Push Service SDK [here](http://developer.blackberry.com/java/documentation/push_service_sdk.html).
The low-level API reference for the Push Service SDK can be found [here](http://www.blackberry.com/developers/docs/PushServiceSDK1.2/LowLevelAPI).
The high-level API reference for the Push Service SDK can be found [here](http://www.blackberry.com/developers/docs/PushServiceSDK1.2/HighLevelAPI).


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
