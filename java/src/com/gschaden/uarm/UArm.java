package com.gschaden.uarm;
import jssc.SerialPort;
import jssc.SerialPortException;


class UArm {
	SerialPort serialPort;

	public UArm(String port) throws SerialPortException {
		serialPort = new SerialPort(port);
		System.out.println("Port opened: " + serialPort.openPort());
		System.out.println("Params setted: "
				+ serialPort.setParams(9600, 8, 1, 0));
	}

	void gotoPosition(int p11, int p12, int p13) {
		try {
			serialPort.writeBytes(String.format("1 %d %d %d\n", p11, p12, p13)
					.getBytes());
		} catch (SerialPortException e) {
			e.printStackTrace();
		}
	}
}
