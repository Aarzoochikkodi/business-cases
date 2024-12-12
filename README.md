# business-cases
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Business Cases - SDG Mapping</title>
    <style>
        body {
            font-family: 'Arial', sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f7fa;
        }

        /* Navigation Bar Styles */
        nav {
            background-color: #4b0082; /* Indigo color */
            padding: 15px 0;
            text-align: center;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
        }

        nav a {
            color: white;
            margin: 0 20px;
            text-decoration: none;
            font-weight: bold;
            font-size: 18px;
            text-transform: uppercase;
        }

        nav a:hover {
            color: #d1ecf1;
        }

        /* Business Case Section */
        .business-case-container {
            margin: 40px;
            padding: 0 20px;
        }

        .section-heading {
            text-align: center;
            font-size: 24px;
            font-weight: bold;
            color: #333;
            margin-bottom: 30px;
            text-transform: uppercase;
        }

        .case-content {
            background-color: #fff;
            border-radius: 15px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            padding: 30px;
            margin-bottom: 30px;
        }

        .case-content h3 {
            font-size: 20px;
            color: #333;
            margin-bottom: 15px;
        }

        .case-content p {
            font-size: 16px;
            color: #555;
            margin-bottom: 10px;
        }

        .highlight {
            font-weight: bold;
            color: #333;
        }

        .pros-cons {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 20px;
            margin-top: 30px;
        }

        .pros-cons div {
            background-color: #e9ecef;
            border-radius: 10px;
            padding: 20px;
        }

        .pros-cons h4 {
            font-size: 18px;
            color: #333;
            text-align: center;
            margin-bottom: 15px;
        }

        .code-link {
            display: block;
            text-align: center;
            margin-top: 20px;
            font-size: 16px;
            font-weight: bold;
            color: #007bff;
        }
        
        .code-link a {
            text-decoration: none;
            color: #007bff;
        }
        
        .code-link a:hover {
            color: #004085;
        }
    </style>
</head>
<body>

    <!-- Navigation Bar -->
    <nav>
        <a href="#home">Home</a>
        <a href="#business-cases">Business Cases</a>
        <a href="#sdg-mapping">SDG Mapping</a>
        <a href="#reflection">Reflection</a>
    </nav>

    <!-- Business Case 1: Optimal Road Network Design -->
    <div id="business-cases" class="business-case-container">
        <div class="section-heading">Optimal Road Network Design</div>

        <div class="case-content">
            <h3>Business Case Overview</h3>
            <p><span class="highlight">Relevant SDG:</span> Sustainable Cities and Communities (SDG 11)</p>
            <p><span class="highlight">Target:</span> 11.2 - Provide access to safe, affordable, and sustainable transport systems for all</p>
            <p><span class="highlight">Indicator:</span> 11.2.1 - Proportion of population with convenient access to public transport</p>

            <h4>Approach to Solve the Problem</h4>
            <p>To solve the problem of optimizing road networks, we use <strong>Dijkstra's Algorithm</strong> for finding the shortest path between different locations in a city. This helps in planning efficient routes for transportation systems, minimizing traffic congestion, and reducing fuel consumption.</p>
            <p>Key steps:</p>
            <ul>
                <li>Represent the city's road network as a graph.</li>
                <li>Use Dijkstra’s algorithm to calculate the shortest paths between locations.</li>
                <li>Optimize routes based on time and distance to ensure the most efficient transportation routes.</li>
            </ul>
            
            <div class="code-link">
                <p>Click here to view the <a href="optimal_road_network_code.cpp" target="_blank">C++ Code for Optimal Road Network Design</a></p>
            </div>
        </div>

        <!-- Pros and Cons Section -->
        <div class="pros-cons">
            <div>
                <h4>Pros</h4>
                <ul>
                    <li>Efficient Path Calculation: Minimizes fuel costs and travel time.</li>
                    <li>Works Well in Urban Areas: Ideal for areas with structured road networks.</li>
                    <li>GPS Integration: Seamlessly integrates with modern navigation systems.</li>
                </ul>
            </div>
            <div>
                <h4>Cons</h4>
                <ul>
                    <li>Limited to Non-Negative Weights: Does not handle negative road weights.</li>
                    <li>High Computational Demand: Requires significant resources in dense urban areas.</li>
                    <li>Challenges with Real-Time Updates: Struggles to adapt to sudden roadblocks or traffic changes.</li>
                </ul>
            </div>
        </div>
    </div>

    <!-- Business Case 2: Smart Public Transportation Scheduling -->
    <div class="business-case-container">
        <div class="section-heading">Smart Public Transportation Scheduling</div>

        <div class="case-content">
            <h3>Business Case Overview</h3>
            <p><span class="highlight">Relevant SDG:</span> Sustainable Cities and Communities (SDG 11)</p>
            <p><span class="highlight">Target:</span> 11.2 - Ensure access to sustainable public transport systems</p>
            <p><span class="highlight">Indicator:</span> 11.2.1 - Percentage of urban areas with access to public transport</p>

            <h4>Approach to Solve the Problem</h4>
            <p>The problem of smart public transportation scheduling can be solved using AI and real-time data. The solution uses optimization algorithms to improve the scheduling of buses and trains, reducing waiting times and ensuring that services run when they are most needed.</p>
            <p>Key steps:</p>
            <ul>
                <li>Collect real-time data on passenger flow and transport availability.</li>
                <li>Use AI algorithms to optimize scheduling and improve route efficiency.</li>
                <li>Implement dynamic scheduling updates based on traffic conditions and passenger demand.</li>
            </ul>
            
            <div class="code-link">
                <p>Click here to view the <a href="public_transportation_scheduling_code.cpp" target="_blank">C++ Code for Public Transportation Scheduling</a></p>
            </div>
        </div>

        <!-- Pros and Cons Section -->
        <div class="pros-cons">
            <div>
                <h4>Pros</h4>
                <ul>
                    <li>Increased Efficiency: Reduces wait times and optimizes resources.</li>
                    <li>Improved Public Satisfaction: Provides more reliable transport services.</li>
                    <li>Cost-Effective: Optimized schedules can lead to reduced operational costs.</li>
                </ul>
            </div>
            <div>
                <h4>Cons</h4>
                <ul>
                    <li>High Initial Setup Costs: Requires investment in AI and infrastructure.</li>
                    <li>Data Dependency: Relies on accurate and up-to-date data.</li>
                    <li>Adaptation Period: May take time for public to adjust to new schedules.</li>
                </ul>
            </div>
        </div>
    </div>

    <!-- Business Case 3: Waste and Water Management System -->
    <div class="business-case-container">
        <div class="section-heading">Waste and Water Management System</div>

        <div class="case-content">
            <h3>Business Case Overview</h3>
            <p><span class="highlight">Relevant SDG:</span> Clean Water and Sanitation (SDG 6)</p>
            <p><span class="highlight">Target:</span> 6.3 - Improve water quality and reduce pollution</p>
            <p><span class="highlight">Indicator:</span> 6.3.1 - Proportion of wastewater treated safely</p>

            <h4>Approach to Solve the Problem</h4>
            <p>The solution focuses on optimizing the waste and water management systems using IoT sensors and real-time data analytics. By monitoring water quality, optimizing waste collection routes, and ensuring the safe treatment of wastewater, the system can greatly improve both water and waste management efficiency.</p>
            <p>Key steps:</p>
            <ul>
                <li>Monitor water quality with sensors and real-time data.</li>
                <li>Use optimization algorithms to enhance waste collection routes and schedules.</li>
                <li>Ensure safe and efficient treatment of wastewater using automated systems.</li>
            </ul>
            
            <div class="code-link">
                <p>Click here to view the <a href="waste_water_management_code.cpp" target="_blank">C++ Code for Waste and Water Management</a></p>
            </div>
        </div>

        <!-- Pros and Cons Section -->
        <div class="pros-cons">
            <div>
                <h4>Pros</h4>
                <ul>
                    <li>Improved Water Quality: Ensures safe and clean water sources.</li>
                    <li>Reduced Pollution: Promotes recycling and proper waste management.</li>
                    <li>Cost-Effective: Efficient resource use reduces operational costs.</li>
                </ul>
            </div>
            <div>
                <h4>Cons</h4>
                <ul>
                    <li>High Initial Investment: Requires infrastructure and technology upgrades.</li>
                    <li>Data Dependency: Relies on sensor accuracy and real-time data processing.</li>
                    <li>Complex Maintenance: Requires regular monitoring and system maintenance.</li>
                </ul>
            </div>
        </div>
    </div>

</body>
</html>
