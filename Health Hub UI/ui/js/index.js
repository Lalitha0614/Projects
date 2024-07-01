
      // Add this inside the script tag
// Add this inside the script tag
function updateStepsPerformance() {
    const targetSteps = parseInt(document.getElementById('targetSteps').value) || 0;
    const enteredSteps = parseInt(document.getElementById('enteredSteps').value) || 0;
  
    let performanceLevel = '';
    let performanceColor = ''; // New variable to store performance color
    
    if (enteredSteps >= 25000) {
        performanceLevel = 'Outstanding';
        performanceColor = 'green';
    } else if (enteredSteps > 12000) {
        performanceLevel = 'Excellent';
        performanceColor = 'orange';
    } else if (enteredSteps >= 7000) {
        performanceLevel = 'Good';
        performanceColor = 'rgb(226, 199, 140)';
    } else if (enteredSteps >= 3000) {
        performanceLevel = 'Need Improvement';
        performanceColor = 'yellow';
    } else if (enteredSteps > 0) {
        performanceLevel = 'Bad';
        performanceColor = 'red';
    } else {
        performanceLevel = '-';
    }
  
    // Display performance level with the specified color
    const performanceContainer = document.getElementById('performanceContainer');
    performanceContainer.innerHTML = `<strong>Performance:</strong> <span style="color: ${performanceColor};">${performanceLevel}</span>`;
  }
  
  // Attach the updateStepsPerformance function to the input change event
  document.getElementById('enteredSteps').addEventListener('input', updateStepsPerformance);
  
  // Initial call to updateStepsPerformance to calculate and display performance on page load
  updateStepsPerformance();
  
  
  function updateHeartCondition() {
      const age = parseInt(document.getElementById('age').value) || 0;
      const heartRate = parseInt(document.getElementById('Heartrate').value) || 0;
  
      let heartCondition = '';
  
      if (age > 0) {
          if (age < 18) {
              heartCondition = 'Age < 18 - Consult doctor';
          } else if (age >= 18 && age <= 30) {
              if (heartRate >= 60 && heartRate <= 100) {
                  heartCondition = 'Your Heart is normal in condition';
              } else {
                  heartCondition = 'Your Heart is Abnormal in condition';
              }
          } else if (age > 30 && age <= 50) {
              if (heartRate >= 50 && heartRate <= 90) {
                  heartCondition = 'Your Heart is normal in condition';
              } else {
                  heartCondition = 'Your Heart is Abnormal in condition';
              }
          } else if (age > 50 && age <= 65) {
              if (heartRate >= 45 && heartRate <= 85) {
                  heartCondition = 'Your Heart is normal in condition';
              } else {
                  heartCondition = 'Your Heart is Abnormal in condition';
              }
          } else if (age > 65) {
              if (heartRate >= 40 && heartRate <= 80) {
                  heartCondition = 'Your Heart is normal in condition';
              } else {
                  heartCondition = 'Your Heart is Abnormal in condition';
              }
          } else {
              heartCondition = 'Your Heart is Abnormal in condition';
          }
  
          // Check for 'Abnormal' heart condition and set the output to red
          if (heartCondition === 'Age < 18 - Consult doctor') {
              heartCondition = '<span style="color: red;">' + heartCondition + '</span>';
          }
          if (heartCondition === 'Your Heart is normal in condition') {
            heartCondition = '<span style="color: #00ff08;">' + heartCondition + '</span>';
        }
        if (heartCondition === 'Your Heart is Abnormal in condition') {
            heartCondition = '<span style="color: red;">' + heartCondition + '</span>';
        }
  
      } else {
          heartCondition = '';
      }
  
  
      // Display Heart Condition in the specified container
      const heartConditionContainer = document.getElementById('heartConditionContainer');
      heartConditionContainer.innerHTML = `${heartCondition}`;
  }
  
  // Attach the updateHeartCondition function to the input change event
  document.getElementById('age').addEventListener('input', updateHeartCondition);
  document.getElementById('Heartrate').addEventListener('input', updateHeartCondition);
  
  // Initial call to updateHeartCondition to calculate and display Heart Condition on page load
  updateBMI();
  updateHeartCondition();
  
  function updateBMI() {
      const weight = parseFloat(document.getElementById('weight').value) || 0;
      const height = parseFloat(document.getElementById('height').value) || 0;
  
      // Calculate BMI
      const bmi = (weight / (height * height)).toFixed(2);
  
      // Display BMI in the specified container
      const bmiContainer = document.getElementById('bmiContainer');
      bmiContainer.innerHTML = `<strong>BMI:</strong> ${bmi}`;
  }
  
  // Attach the updateBMI function to the input change event
  document.getElementById('weight').addEventListener('input', updateBMI);
  document.getElementById('height').addEventListener('input', updateBMI);
  
  // Initial call to updateBMI to calculate and display BMI on page load
  updateBMI();
  
  var images = ["images/image1.jpg", "images/image2.jpg", "images/image3.jpg", "images/image4.jpg", "images/image5.jpg"];
  var currentImageIndex = 0;
  
  function updateWeeklyProgressImage() {
      var canvas = document.getElementById("weeklyProgressCanvas");
      var ctx = canvas.getContext("2d");
      var img = new Image();
  
      img.onload = function () {
          ctx.clearRect(0, 0, canvas.width, canvas.height);
          ctx.drawImage(img, 0, 0, canvas.width, canvas.height);
      };
  
      img.src = images[currentImageIndex];
      currentImageIndex = (currentImageIndex + 1) % images.length;
  }
  
  // Update image every 5 seconds
  var timer = setInterval(updateWeeklyProgressImage, 3000);
  
  function updateChartPage() {
      // Get the data from the input fields
      const mondayCalories = parseInt(document.getElementById('MondayCalories').value) || 0;
      const tuesdayCalories = parseInt(document.getElementById('TuesdayCalories').value) || 0;
      const wednesdayCalories = parseInt(document.getElementById('WednesdayCalories').value) || 0;
      const thursdayCalories = parseInt(document.getElementById('ThursdayCalories').value) || 0;
      const fridayCalories = parseInt(document.getElementById('FridayCalories').value) || 0;
      const saturdayCalories = parseInt(document.getElementById('SaturdayCalories').value) || 0;
      const sundayCalories = parseInt(document.getElementById('SundayCalories').value) || 0;
  
      // Open the chart.html page with the updated dat
      window.open(`html/graph.html?monday=${mondayCalories}&tuesday=${tuesdayCalories}&wednesday=${wednesdayCalories}&thursday=${thursdayCalories}&friday=${fridayCalories}&saturday=${saturdayCalories}&sunday=${sundayCalories}`, '_blank');
  }
  
  // Initial image update
  updateWeeklyProgressImage();
  
  
  
  