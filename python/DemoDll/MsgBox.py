from ctypes import cdll

dll = cdll.LoadLibrary('.\\DemoDll.dll')
dll.MsgBox(b'Text From Python')