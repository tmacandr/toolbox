# Using (Xilinx) Vivado Integrated Logic Analyser (ILA)

The following are raw notes, from a software developer's perspective, on
using the Vivado tool to debug software that interacts with an
FPGA design.

An **Integrated Logic Analyzer** (ILA) is additional FPGA circuitry added
to a design.  The ILA allows examination (i.e. **probe**) of the behavior
of an FPGA circuit, usually in response to software commands written to
registers.  The ILA is (likely) not included in the final FPGA product.
It is only appended to the base FPGA circuitry and allows the developer to
observe/probe circuit behavior, mostly to debug software, but one might
even uncover circuitry bugs.

## 1) Discussion

The FPGA engineer(s) design the base circuitry.  They call this the **IP**,
which means _Intellectual-Property_.  They also often refer to it as the
**Register Transfer Language** (RTL).  It's all evolutionary terminology
from the olden days when the first circuit designs were implemented using
**Verilog Hardware Definition Lanaguage** (VHDL), etc.  A lot has happened
in 50 years.

The following are the steps followed to load an ILA and set triggers on
a Xilinx **VCU128 Evaluation Board**.  The base Xilinx FPGA chip is the
**Virtex UltraScale+ VU37P**.  Again, the FPGA specifics are likely
over my head, but the steps that follow are intended to be generic
enough that a software developer can debug software that interacts
with defined registers of the FPGA system.

Also, the specific case was that the FPGA system used/implemented a
**AXI** bus system.

Discuss here how the _brains_ at **ARM** came up with their Advanced
Modular Interface (or such) bus and then Xilinx adopted and came up with
**Advanced eXtensible Interface** (AXI) and also **AXI-lite**, a less
flexible but simpler (?) bus interface.

Then, discus here my "opinion" that AXI is a squishy VME interface that allows
software to write directly to registers via an address available to
the CPU bus. 

### 1.1) Serial Port and JTAG Connection

Describe here how a **VCU128** board has two connections:
1. JTAG

   Allows download/install of the FPGA-ware:
   ```
   .bit - The FPGA-ware, aka IP
   .xsa - Interface to allow load/start/run of ELF on processor
   .elf - Runtime executable image targeted to the processor
   ```

2. Serial port

   Allows IO between host workstation (running Vivado) and any instantiated
   CPU on the FPGA.  Likely CPU installation is the **Microblaze Processor**.

## 2) Vivado Start

Start 'gnome-terminal'

Run following commands
```
   #!/bin/bash
   module use --append <path-to-Xilinx-installation>
   
   VDIR=<path-to-Xilinx-installation>
   VBIN=$VDIR/bin
   PATH=$PATH:$VBIN
   VEXE=$VBIN/vivado
   #possibly set TMPDIR if /tmp not available
   #export TMPDIR=$HOME/<work-area>
   source $VDIR/settings64.sh
   $VXE &
```
The **Vivado** tool starts and the base start-up window is shown.

![vivado_start_window](./Images/vivado_pg_00.jpg "Vivado start dialog")

If starting an ILA session for the first time, continue to Section **3**.

If hardware selection has been done previously, skip to Section **5**.

## 3) Setup - Open Hardware Manager
 
Follow steps shown here to open the **hardware manager**.

![hw_manager](./Images/vivado_pg_01.jpg "HW Manager")

## 4) Select Target Hardware

The next diagram shows steps to open/activate a **hardware target**.

Follow the steps of the _open new hardware target_ **wizard**.

![target_hardware](./Images/vivado_pg_02.jpg "hw target wizard")

The **host** is local to your workstation **127.0.0.1**

The **port** always seems to be **3121**.

Need to know what the **serial number** to the board.

If the board is already connected to the host workstation via a
serial/JTAG line, then the serial number may be available by using
the following Linux tools:
```
   #!/bin/bash
   DEVS=`ls -l /dev/ttyUSB* | sort -tB -k2 -g`
   for e in $DEVS; do
      udevadm info --query=property --name=$DEVS
   done
```
Note:
```
   Use 'jq' tool to pares JSON file of information
```

Select the target based on the **serial number**.

![select_tgt_board](./Images/vivado_pg_03.jpg "select board")

## 5) Load Probe (ILA) File - <probe>.ltx

If the target board has been loaded during a previous session, then
select:
```
   Open Recent
       |
       |---> Target
       
   Select the previous board configuration from the previous session
```
At this point, the **probe** window/dialog is shown.

![select_probes](./Images/vivado_pg_04.jpg "load probes")

A **probe file** is a list of signal points in the ILA circuitry, which
allows signals in the IP to be observed.  An EE would probably laugh,
but probe signals for a software developer are analogous to _break points_
in source code.

Probe files have the file extension **.ltx**.

## 6) Select Trigger Signals

To specify the signal(s) to probe ... called _trigger_ signals, press
the **+** sign at the **Trigger Setup** sub-window.

![select_trigger](./Images/vivado_pg_05.jpg "trigger events")

When the trigger condition occurs the ILA will measure all the signals
defined in the probe file and display them on the GUI.

Setup trigger events:

More

![select_signals](./Images/vivado_pg_06.jpg "select signals")

More

![change_settings](./Images/vivado_pg_07.jpg "chagne settings")

More

![trigger_setup](./Images/vivado_pg_08.jpg "trigger setup")

More

![trigger_buttons](./Images/vivado_pg_09.jpg "trigger setup")

More

![trigger_event](./Images/vivado_pg_10.jpg "trigger setup")

## 7) Shutdown

Show 'graceful' exit here.

Not sure if have to disconnect from hardware (via JTAG connection)
or just do "exit".

# References

NOTE - Running Vivado may not render correctly on full 32-bit graphics
       environment.
```
       Some "colors" are rendered as "see through".

       I forget how, but there may be a start option on the
       "Windows to Linux" 'mstsc' tool to select a 24-bit color
       pallette.  Vivado will render correctly then.
```

Tcl script to load/install FPGA-ware.

Use the Xilinx tool `xsct` and specify the following Tcl script.

ATTEN - This is for load/install to a **Virtex UltraScale+ VU37P** on a
**VCU-128** Evaluation board.  The `xsct` tool has been deprecated by
Xilinx (actually AMD) for later products.  The **VCU-128** is no longer
available from Xilinx.

Check this, but I think the syntax is:
```
   xsct load_board.tcl
```
where `xsct` is in **$PATH**.

The following is the `load_board.tcl`:

```
   set XSA_FILE      [lindex $argv 0]
   set BIT_FILE      [lindex $argv 1]
   set ELF_FILE      [lindex $argv 2]
   set SERIAL_NUM    [lindex $argv 3]

   puts "--->    XSA File...: $XSA_FILE"
   puts "--->    BIT File...: $BIT_FILE"
   puts "--->    ELF File...: $ELF_FILE"
   puts "--->    Tgt ID.....: $SERIAL_NUM"
   
   connect -url tcp:127.0.0.1:3121
   
   puts "---> targets to load FPGA bit file"
   
   targets -set -filter {target_ctx =~ "*${SERIAL_NUM}*" && name =~ "xcvu37p"}
   
   puts "---> load bit file"
   
   loadhw -hw $XSA_FILE -regs
   
   puts "---> loadhw"
   
   loadhw -hw $XSA_FILE -regs
   
   puts "---> reset"
   
   rst -system
   
   puts "---> download elf"
   
   dow $ELF_FILE
   
   puts "---> con"
   
   con
   
   puts "---> done"
```

