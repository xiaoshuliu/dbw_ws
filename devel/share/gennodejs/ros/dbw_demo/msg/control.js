// Auto-generated. Do not edit!

// (in-package dbw_demo.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class control {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.brake = null;
      this.throttle = null;
      this.steering = null;
      this.steering_mult = null;
      this.gear_cmd = null;
      this.turn_signal_cmd = null;
    }
    else {
      if (initObj.hasOwnProperty('brake')) {
        this.brake = initObj.brake
      }
      else {
        this.brake = 0.0;
      }
      if (initObj.hasOwnProperty('throttle')) {
        this.throttle = initObj.throttle
      }
      else {
        this.throttle = 0.0;
      }
      if (initObj.hasOwnProperty('steering')) {
        this.steering = initObj.steering
      }
      else {
        this.steering = 0.0;
      }
      if (initObj.hasOwnProperty('steering_mult')) {
        this.steering_mult = initObj.steering_mult
      }
      else {
        this.steering_mult = false;
      }
      if (initObj.hasOwnProperty('gear_cmd')) {
        this.gear_cmd = initObj.gear_cmd
      }
      else {
        this.gear_cmd = 0;
      }
      if (initObj.hasOwnProperty('turn_signal_cmd')) {
        this.turn_signal_cmd = initObj.turn_signal_cmd
      }
      else {
        this.turn_signal_cmd = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type control
    // Serialize message field [brake]
    bufferOffset = _serializer.float32(obj.brake, buffer, bufferOffset);
    // Serialize message field [throttle]
    bufferOffset = _serializer.float32(obj.throttle, buffer, bufferOffset);
    // Serialize message field [steering]
    bufferOffset = _serializer.float32(obj.steering, buffer, bufferOffset);
    // Serialize message field [steering_mult]
    bufferOffset = _serializer.bool(obj.steering_mult, buffer, bufferOffset);
    // Serialize message field [gear_cmd]
    bufferOffset = _serializer.int16(obj.gear_cmd, buffer, bufferOffset);
    // Serialize message field [turn_signal_cmd]
    bufferOffset = _serializer.int16(obj.turn_signal_cmd, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type control
    let len;
    let data = new control(null);
    // Deserialize message field [brake]
    data.brake = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [throttle]
    data.throttle = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [steering]
    data.steering = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [steering_mult]
    data.steering_mult = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [gear_cmd]
    data.gear_cmd = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [turn_signal_cmd]
    data.turn_signal_cmd = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 17;
  }

  static datatype() {
    // Returns string type for a message object
    return 'dbw_demo/control';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9198f2552165ab2d06332d076b42111d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
      float32 brake
      float32 throttle
      float32 steering
      bool steering_mult
      int16 gear_cmd
      int16 turn_signal_cmd
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new control(null);
    if (msg.brake !== undefined) {
      resolved.brake = msg.brake;
    }
    else {
      resolved.brake = 0.0
    }

    if (msg.throttle !== undefined) {
      resolved.throttle = msg.throttle;
    }
    else {
      resolved.throttle = 0.0
    }

    if (msg.steering !== undefined) {
      resolved.steering = msg.steering;
    }
    else {
      resolved.steering = 0.0
    }

    if (msg.steering_mult !== undefined) {
      resolved.steering_mult = msg.steering_mult;
    }
    else {
      resolved.steering_mult = false
    }

    if (msg.gear_cmd !== undefined) {
      resolved.gear_cmd = msg.gear_cmd;
    }
    else {
      resolved.gear_cmd = 0
    }

    if (msg.turn_signal_cmd !== undefined) {
      resolved.turn_signal_cmd = msg.turn_signal_cmd;
    }
    else {
      resolved.turn_signal_cmd = 0
    }

    return resolved;
    }
};

module.exports = control;
