// Auto-generated. Do not edit!

// (in-package test_pkg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Num {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.num = null;
      this.bigger_num = null;
      this.NumNumNum = null;
    }
    else {
      if (initObj.hasOwnProperty('num')) {
        this.num = initObj.num
      }
      else {
        this.num = 0;
      }
      if (initObj.hasOwnProperty('bigger_num')) {
        this.bigger_num = initObj.bigger_num
      }
      else {
        this.bigger_num = 0;
      }
      if (initObj.hasOwnProperty('NumNumNum')) {
        this.NumNumNum = initObj.NumNumNum
      }
      else {
        this.NumNumNum = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Num
    // Serialize message field [num]
    bufferOffset = _serializer.int8(obj.num, buffer, bufferOffset);
    // Serialize message field [bigger_num]
    bufferOffset = _serializer.int16(obj.bigger_num, buffer, bufferOffset);
    // Serialize message field [NumNumNum]
    bufferOffset = _serializer.int8(obj.NumNumNum, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Num
    let len;
    let data = new Num(null);
    // Deserialize message field [num]
    data.num = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [bigger_num]
    data.bigger_num = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [NumNumNum]
    data.NumNumNum = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'test_pkg/Num';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6984b6b29b1a95096bc45ddb5f33ba67';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8 num
    int16 bigger_num
    int8 NumNumNum
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Num(null);
    if (msg.num !== undefined) {
      resolved.num = msg.num;
    }
    else {
      resolved.num = 0
    }

    if (msg.bigger_num !== undefined) {
      resolved.bigger_num = msg.bigger_num;
    }
    else {
      resolved.bigger_num = 0
    }

    if (msg.NumNumNum !== undefined) {
      resolved.NumNumNum = msg.NumNumNum;
    }
    else {
      resolved.NumNumNum = 0
    }

    return resolved;
    }
};

module.exports = Num;
