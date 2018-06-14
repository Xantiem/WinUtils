#include <Python.h>
#include <Windows.h>

PyDoc_STRVAR(winDocs, "Shutdown(condition) - Shut down the device, condition is logged by the system\nRestart(condition) - Restart the device, condition is logged by the system\nLogOut(condition) - Logs out the user from the device, condition is logged by the system\n\nMajor flags:\n\nSHTDN_REASON_MAJOR_APPLICATION: Application issue\nSHTDN_REASON_MAJOR_HARDWARE: Hardware issue\nSHTDN_REASON_MAJOR_OPERATINGSYSTEM: Operating system issue\nSHTDN_REASON_MAJOR_OTHER: Other issue\nSHTDN_REASON_MAJOR_POWER: Power failure\nSHTDN_REASON_MAJOR_SOFTWARE: Software issue\nSHTDN_REASON_MAJOR_SYSTEM: System failure\n\nMinor flags:\n\nSHTDN_REASON_MINOR_BLUESCREEN: Blue screen crash event.\nSHTDN_REASON_MINOR_CORDUNPLUGGED: Unplugged\nSHTDN_REASON_MINOR_DISK: Disk\nSHTDN_REASON_MINOR_ENVIRONMENT: Environment\nSHTDN_REASON_MINOR_HARDWARE_DRIVER: Driver\nSHTDN_REASON_MINOR_HOTFIX: Hot Fix\nSHTDN_REASON_MINOR_HOTFIX_UNINSTALL: Hot fix uninstallation\nSHTDN_REASON_MINOR_HUNG: Unresponsive\nSHTDN_REASON_MINOR_INSTALLATION: Installation\nSHTDN_REASON_MINOR_MAINTENANCE: Maintenance\nSHTDN_REASON_MINOR_MMC: MMC issue\nSHTDN_REASON_MINOR_NETWORK_CONNECTIVITY: Network connectivity.\nSHTDN_REASON_MINOR_NETWORKCARD: Network card\nSHTDN_REASON_MINOR_OTHER: Other issue\nSHTDN_REASON_MINOR_OTHERDRIVER: Other driver event\nSHTDN_REASON_MINOR_POWER_SUPPLY: Power supply\nSHTDN_REASON_MINOR_PROCESSOR: Processor\nSHTDN_REASON_MINOR_RECONFIG: Reconfigure\nSHTDN_REASON_MINOR_SECURITY: Secuity issue\nSHTDN_REASON_MINOR_SECURITYFIX: Security patch\nSHTDN_REASON_MINOR_SECURITYFIX_UNINSTALL: Security patch uninstallation\nSHTDN_REASON_MINOR_SERVICEPACK: Service pack\nSHTDN_REASON_MINOR_SERVICEPACK_UNINSTALL: Service pack uninstallation\nSHTDN_REASON_MINOR_TERMSRV: Terminal services\nSHTDN_REASON_MINOR_UNSTABLE: Unstable\nSHTDN_REASON_MINOR_UPGRADE: Upgrade\nSHTDN_REASON_MINOR_WMI: WMI issue\n\nAdditional flags (optional):\n\nSHTDN_REASON_FLAG_USER_DEFINED: The reason code is defined by the user. If this flag is not present, the reason code is defined by the system\nSHTDN_REASON_FLAG_PLANNED:The shutdown was planned. The system generates a System State Data (SSD) file. This file contains system state information such as the processes, threads, memory usage, and configuration.If this flag is not present, the shutdown was unplanned.Notification and reporting options are controlled by a set of policies.For example, after logging in, the system displays a dialog box reporting the unplanned shutdown if the policy has been enabled.An SSD file is created only if the SSD policy is enabled on the system\n\n See https://msdn.microsoft.com/en-us/library/aa376885(v=vs.85).aspx");

static PyObject * sys_shutdown(PyObject *self, PyObject *args) {
	int val;

	if (!PyArg_ParseTuple(args, "i", &val))
		return NULL;

	ExitWindowsEx(EWX_POWEROFF, val); // Shutdown
	return Py_BuildValue(""); // Return nothing 
}

static PyObject * sys_restart(PyObject *self, PyObject *args) {
	int val;

	if (!PyArg_ParseTuple(args, "i", &val))
		return NULL;
	
	ExitWindowsEx(EWX_REBOOT, val); // Restart
	return Py_BuildValue(""); // Return nothing
}

static PyObject * sys_log_out(PyObject *self, PyObject *args) {
	int val;

	if (!PyArg_ParseTuple(args, "i", &val))
		return NULL;

	ExitWindowsEx(EWX_LOGOFF, val); // Log out
	return Py_BuildValue(""); // Return nothing
}

static PyMethodDef localMethods[] = {
	{ "Shutdown", (PyCFunction)sys_shutdown, METH_VARARGS, "Shuts down the device.  Requires one argument to be logged by the system"}, // Shutdown
	{ "Restart", (PyCFunction)sys_restart, METH_VARARGS, "Restarts the device.  Requires one argument to be logged by the system"}, // Restart
	{ "LogOut", (PyCFunction)sys_log_out, METH_VARARGS, "Logs the user out of the device.  Requires one argument to be logged by the system" }, // Log out
	{ NULL, NULL, 0, NULL }
};

static struct PyModuleDef func = {
	PyModuleDef_HEAD_INIT,
	"WinUtils",
	winDocs,
	-1,
	localMethods,
};

PyMODINIT_FUNC PyInit_WinUtils(void) {
	PyObject *module = PyModule_Create(&func); // Create module

	// Major flags:

	PyModule_AddIntMacro(module, SHTDN_REASON_MAJOR_APPLICATION);
	PyModule_AddIntMacro(module, SHTDN_REASON_MAJOR_HARDWARE);
	PyModule_AddIntMacro(module, SHTDN_REASON_MAJOR_OPERATINGSYSTEM);
	PyModule_AddIntMacro(module, SHTDN_REASON_MAJOR_OTHER);
	PyModule_AddIntMacro(module, SHTDN_REASON_MAJOR_POWER);
	PyModule_AddIntMacro(module, SHTDN_REASON_MAJOR_SOFTWARE);
	PyModule_AddIntMacro(module, SHTDN_REASON_MAJOR_SYSTEM);

	// Minor flags:

	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_BLUESCREEN);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_CORDUNPLUGGED);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_DISK);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_ENVIRONMENT);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_HARDWARE_DRIVER);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_HOTFIX);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_HOTFIX_UNINSTALL);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_HUNG);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_INSTALLATION);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_MAINTENANCE);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_MMC);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_NETWORK_CONNECTIVITY);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_NETWORKCARD);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_OTHER);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_OTHERDRIVER);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_POWER_SUPPLY);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_PROCESSOR);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_RECONFIG);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_SECURITY);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_SECURITYFIX);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_SECURITYFIX_UNINSTALL);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_SERVICEPACK);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_SERVICEPACK_UNINSTALL);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_TERMSRV);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_UNSTABLE);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_UPGRADE);
	PyModule_AddIntMacro(module, SHTDN_REASON_MINOR_WMI);

	// Optional flags

	PyModule_AddIntMacro(module, SHTDN_REASON_FLAG_USER_DEFINED);
	PyModule_AddIntMacro(module, SHTDN_REASON_FLAG_PLANNED);

	return module;
}