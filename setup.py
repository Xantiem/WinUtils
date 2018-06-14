from setuptools import setup, Extension

long_description = """# WinUtils
A module for Windows utilities

>**Installation:**

    pip install winutils

>**Examples:**

    import WinUtils as wu
    wu.Shutdown(wu.SHTDN_REASON_MINOR_OTHER) # Shutdown other error, minor
    wu.Restart(wu.SHTDN_REASON_MAJOR_SOFTWARE) # Restart Software error, major
    wu.LogOut(wu.SHTDN_REASON_MINOR_HOTFIX) # Log out user hot fix, minor


>**Reference:**

**Functions:**

`Shutdown(condition)` - Shut down the device, condition is logged by the system
`Restart(condition)` - Restart the device, condition is logged by the system
`LogOut(condition)` - Logs out the user from the device, condition is logged by the system

**All Error Codes:**

Major flags:

`SHTDN_REASON_MAJOR_APPLICATION`: Application issue

`SHTDN_REASON_MAJOR_HARDWARE`: Hardware issue

`SHTDN_REASON_MAJOR_OPERATINGSYSTEM`: Operating system issue

`SHTDN_REASON_MAJOR_OTHER`: Other issue

`SHTDN_REASON_MAJOR_POWER`: Power failure

`SHTDN_REASON_MAJOR_SOFTWARE`: Software issue

`SHTDN_REASON_MAJOR_SYSTEM`: System failure

Minor flags:

`SHTDN_REASON_MINOR_BLUESCREEN`: Blue screen crash event.

`SHTDN_REASON_MINOR_CORDUNPLUGGED`: Unplugged

`SHTDN_REASON_MINOR_DISK`: Disk

`SHTDN_REASON_MINOR_ENVIRONMENT`: Environment

`SHTDN_REASON_MINOR_HARDWARE_DRIVER`: Driver

`SHTDN_REASON_MINOR_HOTFIX`: Hot Fix

`SHTDN_REASON_MINOR_HOTFIX_UNINSTALL`: Hot fix uninstallation

`SHTDN_REASON_MINOR_HUNG`: Unresponsive

`SHTDN_REASON_MINOR_INSTALLATION`: Installation

`SHTDN_REASON_MINOR_MAINTENANCE`: Maintenance

`SHTDN_REASON_MINOR_MMC`: MMC issue

`SHTDN_REASON_MINOR_NETWORK_CONNECTIVITY`: Network connectivity.

`SHTDN_REASON_MINOR_NETWORKCARD`: Network card

`SHTDN_REASON_MINOR_OTHER`: Other issue

`SHTDN_REASON_MINOR_OTHERDRIVER`: Other driver event

`SHTDN_REASON_MINOR_POWER_SUPPLY`: Power supply

`SHTDN_REASON_MINOR_PROCESSOR`: Processor

`SHTDN_REASON_MINOR_RECONFIG`: Reconfigure

`SHTDN_REASON_MINOR_SECURITY`: Secuity issue

`SHTDN_REASON_MINOR_SECURITYFIX`: Security patch

`SHTDN_REASON_MINOR_SECURITYFIX_UNINSTALL`: Security patch uninstallation

`SHTDN_REASON_MINOR_SERVICEPACK`: Service pack

`SHTDN_REASON_MINOR_SERVICEPACK_UNINSTALL`: Service pack uninstallation

`SHTDN_REASON_MINOR_TERMSRV`: Terminal services

`SHTDN_REASON_MINOR_UNSTABLE`: Unstable

`SHTDN_REASON_MINOR_UPGRADE`: Upgrade

`SHTDN_REASON_MINOR_WMI`: WMI issue

Additional flags (optional):

`SHTDN_REASON_FLAG_USER_DEFINED`: The reason code is defined by the user. If this flag is not present, the reason code is defined by the system

`SHTDN_REASON_FLAG_PLANNED`:The shutdown was planned. The system generates a System State Data (SSD) file. This file contains system state information such as the processes, threads, memory usage, and configuration.If this flag is not present, the shutdown was unplanned.Notification and reporting options are controlled by a set of policies.For example, after logging in, the system displays a dialog box reporting the unplanned shutdown if the policy has been enabled.An SSD file is created only if the SSD policy is enabled on the system

 See https://msdn.microsoft.com/en-us/library/aa376885(v=vs.85).aspx """

module = Extension(
	"WinUtils", 
	sources = ["main.c"],
        libraries = ["user32"]
)

setup (
	name = "WinUtils",
	version = "1.1.1",
        description = "A module to provide simplified system calls on Windows",
        author = "Simon",
        url = "https://github.com/Simon3335/WinUtils",
        license = 'MIT',
        python_requires = '>=3',
        long_description=long_description,
        long_description_content_type="text/markdown",
        data_files = ["LICENSE"], 
	ext_modules = [module])
