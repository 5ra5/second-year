### **2.1.6 Memory Constraints**
80-120 words

This section is about **how much memory the system is allowed to use**, both in:

- **Primary memory** (RAM)
    
- **Secondary memory** (storage like a hard drive or SSD)
    

You need to describe:

- Whether there are limits on memory usage (for example, if your app will run on older devices or specific hardware).
    
- How much memory is available and how that affects your app’s design.
    

✅ **Example:**

> The mobile application must run on devices with a minimum of 3 GB RAM and 64 GB of storage. The app’s memory footprint should not exceed 500 MB during normal operation.

If there are **no real limits**, you can simply say:

> There are no specific memory constraints for this application.

So basically: this section defines _how heavy or light_ your app can be.

---

### **2.1.7 Operations**
150-200 words

This describes **how and when the system will be used** — both normal and special operations.

You’re focusing on:

- **Modes of operation** (e.g., online/offline, admin vs. user mode)
    
- **Interactive vs unattended operation** (does it need constant user input or can it run on its own?)
    
- **Data processing support** (like how data is input, stored, or backed up)
    
- **Backup and recovery** (what happens if the system crashes?)
    

✅ **Example:**

> The app will operate interactively during business hours, allowing users to manage bookings in real time. A nightly automated backup will run at 2 AM. During this time, the system will not be accessible to users.

Essentially, this section is about **the day-to-day workflow** and **special procedures** that might affect how you design your system.

---

### **2.1.8 Site Adaptation Requirements**
100-150 words

This section covers **what needs to be set up or changed in the environment where the system will be installed**.

That can include:

- Hardware that must be installed (e.g., servers, cooling, generators)
    
- Software setup (e.g., database configurations, APIs)
    
- Initialization or data loading requirements (e.g., preloading existing records)
    

✅ **Example:**

> Before installation, the client must ensure that the company’s existing MySQL server has been upgraded to version 8.0 or higher. New data tables for the inventory system must be created and populated prior to deployment.

So this part answers:  
➡️ _“What does the client or site need to have or do before our software can run properly?”_

---

### **2.2 Product Functions**
250-400 words

This is where you **summarize what your software actually does** — its **main features and functions**, written in **plain, customer-friendly language**.

You’re describing the _“what”_, not the _“how.”_

✅ **Example:**

> The system will allow users to register accounts, log in, view and update their profiles, and make reservations. Administrators can manage users, approve reservations, and view system reports.

It helps to use:

- Bullet points for functions
    
- Simple diagrams or charts to show relationships between features (like a goal model or function hierarchy)
    

This section is **the core of the SRS** — it defines **what your app must be capable of doing**.

---

### **2.3 User Characteristics**
150-250 words

Here you describe **who will be using the system**, including:

- Their **experience level** (e.g., tech-savvy or not)
    
- Their **roles** (e.g., admin, manager, end-user)
    
- Any **traits** that affect design decisions (like accessibility needs or job context)
    

You’re not listing requirements here — just describing the **users** so that later design choices make sense.

✅ **Example:**

> The system’s primary users are retail staff with basic computer skills. Administrative users have moderate technical knowledge and are responsible for managing user accounts and viewing reports.

So this section answers:  
➡️ _“Who are we building this for, and what do we need to keep in mind about them?”_

---

### **2.4 Constraints**
150-250 words

This section lists **anything that limits how the system can be built** — legal, technical, or environmental factors that developers _must_ follow.

Typical constraint types include:

- **Regulatory or policy constraints** (e.g., GDPR data rules)
    
- **Hardware limitations** (e.g., must run on existing POS terminals)
    
- **Interface constraints** (e.g., must integrate with company’s billing software)
    
- **Safety/security** considerations
    
- **Reliability and timing** requirements
    

✅ **Example:**

> The system must comply with the company’s IT security policies and use encrypted HTTPS communication. It must also integrate with the existing payroll management system.

So this part answers:  
➡️ _“What rules or limitations must the software follow?”_

---

### **2.5 Assumptions and Dependencies**
100-150 words

This is a “catch-all” section for **things you assume will be true or are outside your control**, but which affect your design.

Examples:

- Assuming the customer will provide an updated operating system
    
- Depending on an external API being available
    
- Assuming users will have internet access
    

✅ **Example:**

> It is assumed that all users will have stable internet connections. The system depends on the company’s existing authentication server to validate user credentials.

If those assumptions turn out false, the system might not work as expected — that’s why they need to be clearly listed.

So this part answers:  
➡️ _“What external factors or assumptions are we relying on?”
