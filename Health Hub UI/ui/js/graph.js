// Retrieve data from the query parameters
const queryString = window.location.search;
const urlParams = new URLSearchParams(queryString);

// Populate netCalories array with the provided values
const netCalories = [
    parseInt(urlParams.get('monday')) || 0,
    parseInt(urlParams.get('tuesday')) || 0,
    parseInt(urlParams.get('wednesday')) || 0,
    parseInt(urlParams.get('thursday')) || 0,
    parseInt(urlParams.get('friday')) || 0,
    parseInt(urlParams.get('saturday')) || 0,
    parseInt(urlParams.get('sunday')) || 0
];

// Calculate average calories
const averageCalories = netCalories.reduce((acc, value) => acc + value, 0) / netCalories.length;

// Create the chart (change type to 'line')
var caloriesChart = new Chart(document.getElementById('caloriesChart').getContext('2d'), {
    type: 'line',
    data: {
        labels: ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday'],
        datasets: [{
            label: 'Net Calories',
            borderColor: '#4caf50',
            data: netCalories,
            fill: false
        }, {
            label: 'Average Calories',
            borderColor: 'blue',
            borderDash: [5, 5],
            data: [averageCalories, averageCalories, averageCalories, averageCalories, averageCalories, averageCalories, averageCalories],
            fill: false
        }]
    },
    options: {
        scales: {
            y: {
                beginAtZero: true
            }
        }
    }
});
