# 💾 Linux Storage: Partitioning & Persistent Mounting

**Author:** Usman O. Olanrewaju (Blu3 Sky)  
**Date:** 2025/01/24  
**Environment:** Fedora (Host), Rocky Linux (Lab), Framework 13

---

## 📝 Lab Overview
This lab documents the process of managing block devices, creating partitions, and configuring the filesystem for persistence. This is a core skill required for the **RHCSA** certification.

### 1. Disk Identification
First, I used `lsblk -f` to identify the target disk (e.g., `/dev/sda`) and verify if any file systems or UUIDs were already present.

### 2. Disk Partitioning with `parted`
I used the `parted` utility for low-level partitioning. 
*Note: Commands like `mkpart` must be executed within the `parted` interactive shell.*

**Steps taken:**
- `mklabel gpt`: Set the partition table type.
- `mkpart`: Defined the partition size and type.

### 3. Persistent Mounting (/etc/fstab)
To ensure the drive mounts automatically on system boot, I added the **UUID** of the partition to the `/etc/fstab` configuration file.

**Configuration Format:**
`UUID=23457549492 /data xfs defaults 0 0`

### 4. Verification
I tested the mount configuration without rebooting by unmounting the drive and running the mount-all command:
```bash
sudo umount /data
sudo mount -a
lsblk -f
 ```


###  🖼️ Lab Evidence

#### 1. Disk Partitioning with Parted
![Partitioning Process](Images-Videos/storage-management.jpeg)

#### 2. File System & UUID Identification
![lsblk Output](Images-Videos/Storage-Management1.jpeg)

#### 3. Persistent Mount Configuration (/etc/fstab)
![fstab configuration](Images-Videos/Storage-management-fstab.jpeg)
#
#
