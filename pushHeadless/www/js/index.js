/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
var app = {
    // Application Constructor
    initialize: function() {
        this.bindEvents();
    },
    // Bind Event Listeners
    //
    // Bind any events that are required on startup. Common events are:
    // 'load', 'deviceready', 'offline', and 'online'.
    bindEvents: function() {
        document.addEventListener('deviceready', this.onDeviceReady, false);
    },
    // deviceready Event Handler
    //
    // The scope of 'this' is the event. In order to call the 'receivedEvent'
    // function, we must explicity call 'app.receivedEvent(...);'
    onDeviceReady: function() {
        var ops = {
            invokeTargetId : "com.example.pushCollector.invoke.push",
            appId : "myAppID"
        };

        app.receivedEvent('deviceready');

        //create pushService object to extra push data
        blackberry.push.PushService.create(ops, app.successCreatePushService, app.failCreatePushService);
    },
    // success callback called when push service object created
    successCreatePushService: function(service) {
        //store push service object
        app.pushService = service;

        //add listener for invokes triggered by pushes
        blackberry.event.addEventListener("invoked", app.onInvoke);
    },
    // fail callback when push service object creation failed
    failCreatePushService: function(result) {
        console.log("Error creating push service object" + result);
    },
    // called when invoked event occurs.
    // ignores anything that isn't a bb.action.PUSH invoke
    onInvoke: function(invokeRequest) {
        if (invokeRequest && invokeRequest.action == "bb.action.PUSH") {
            if (app.pushService) {
                var pushPayload = app.pushService.extractPushPayload(invokeRequest),
                    reader = new window.FileReader();

                //convert blob to string
                reader.readAsText(pushPayload.data);
                reader.onloadend = function() {
                    //update label
                    document.getElementById("lblPush").innerHTML = "Invoked with push: " + reader.result;
                };

                // If an acknowledgement of the push is required (that is, the push was sent as a confirmed push
                // - which is equivalent terminology to the push being sent with application level reliability),
                // then you must either accept the push or reject the push
                if (pushpayload.isAcknowledgeRequired) {
                    // In our sample, we always accept the push, but situations might arise where an application
                    // might want to reject the push (for example, after looking at the headers that came with the push
                    // or the data of the push, we might decide that the push received did not match what we expected
                    // and so we might want to reject it)
                    pushpayload.acknowledge(true);
                }
            }
        }
    },
    // Update DOM on a Received Event
    receivedEvent: function(id) {
        var parentElement = document.getElementById(id);
        var listeningElement = parentElement.querySelector('.listening');
        var receivedElement = parentElement.querySelector('.received');

        listeningElement.setAttribute('style', 'display:none;');
        receivedElement.setAttribute('style', 'display:block;');

        console.log('Received Event: ' + id);
    }
};
