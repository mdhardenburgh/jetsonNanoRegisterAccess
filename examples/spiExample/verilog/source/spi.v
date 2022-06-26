module spiRecieve
(
    input clk,
    input rst,
    input sclk,
    input copi,
    input chipSel,
    output reg[65:0] packet
    
);
    localparam idle
    localparam countAndShift

    reg[1:0] stateTracker;
    reg[32:0] 
    
    
    always@(posedge clk, posedge rst)
    begin
	if(rst == 1'b)
	begin
	    packet = 66'b0;
	    stateTracker = idle;
	end
	else
	begin
	    case(stateTracker)
		idle:
		begin
		    if(chipSel == 1'b0)
		    begin
			
		    end
		end
    
	    endcase
	end
    end

endmodule

module spiTransmit
(
    input clk,
    input rst,
    input sclk,
    input chipSel,
    input[65:0] packet,
    output reg cipo
);

endmodule

//2 FIFOs. One to spiRecive and one to spiTransmit

module spiCommandProcessor
(
    input clk,
    input rst,
    input[65:0] packetIn, //from recieve FIFO
    input[31:0] muxDataInput[31:0],
    output reg[31:0] demuxDataOutput[31:0],
    output reg[65:0] packetOut, //to transmit FIFO
);
    //packet is 66 bits in total
    reg enable;
    reg readOrWrite
    reg[31:0] addr;
    reg[31:0] data;


    localparam idleState = 2'd0;
    localparam readState = 2'd1;
    localparam writeState = 2'd2;
    localparam echoWriteState = 2'd3;
    
    localparam enableActive = 1'b1;

    reg[1:0] stateTracker;

    always@(posedge clk, negedge rst)
    begin
	if(rst == 1'b1)
	begin
	    stateTracker <= 2'b0;
	    returnPacket <= 66'b0;
	end
	
	else
	begin
	    case(stateTracker)
		idleState:
		begin
		    
		    enable = packetIn[65];

		    if(enable == enableActive)
		    begin
			readOrWrite = packetIn[64];
			addr = packetIn[63:32];
			data = packetIn[31:0];

			if(readWrite == readState)
			begin
			    stateTracker = readState;
			end
			else
			begin
			    stateTracker = writeState;
			end
		    end
		    else
		    begin
			stateTracker = idleState;
		    end
		end
		readState:
		begin
		    packetOut[65] = enable;
		    packetOut[64] = readOrWrite; //should be the first bit of 2'd1 or 2'b01
		    packetOut[63:32] = addr;
		    packetOut[31:0] = muxDataInput[addr], //Input from peripheral such as GPIO
		    stateTracker = idleState;
		end
		writeState:
		begin
		    demuxDataOutput[addr] = data
		    stateTracker = echoWriteState;
		end
		echoWriteState:
		begin
		    packetOut[65] = enable;
		    packetOut[64] = readOrWrite;
		    packetOut[63:32] = addr;	
		    //Read register and send back what is in the reg. This is to verify what
		    //what was written was actually written.	    
		    returnPacket[31:0] = muxDataInput[addr];
		    stateTracker = idleState
		end
	    endcase
	end
	
    end 

endmodule

module gpio
(
    input clk,
    input rst,
    input gpio1In,
    input[31:0] dataIn,
    output reg[31:0] register
);
    
    always@(posedge clk, posedge rst)
    begin
	if(rst == 1'b1)
	begin
	    register[0] = 1'b0;
	end
	else
	begin
	    register[0] <= dataIn[0];
	    
	end
    end    
    
    always@(posedge clk, posedge rst)
    begin
	if(rst == 1'b1)
	begin
	    dataOut[1] = 1'b0;
	end
	else
	begin
	    register[1] <= gpio1In;
	end
    end
endmodule
