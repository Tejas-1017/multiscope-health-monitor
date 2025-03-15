import time
import numpy as np
import plotly.graph_objects as go
import gradio as gr

def generate_telemetry(stress_scenario):
    t = np.linspace(0, 4, 200)
    phase = time.time() * 2.0
    ppg = np.sin(2 * np.pi * 1.2 * t + phase) + 0.3 * np.sin(4 * np.pi * 1.2 * t + phase)
    bpm = 135.0 if stress_scenario else 74.0
    spo2 = 91.5 if stress_scenario else 98.4
    temp = 38.2 if stress_scenario else 36.6
    fig = go.Figure(data=go.Scatter(x=t, y=ppg, mode='lines', line=dict(color='#00F3FF', width=2.5)))
    fig.update_layout(title="Live Arterial PPG Optical Waveform", template="plotly_dark", height=320, paper_bgcolor="#0d1117", plot_bgcolor="#161b22")
    return fig, f"{bpm:.0f} BPM", f"{spo2:.1f} %", f"{temp:.1f} °C"

with gr.Blocks(title="Multiscope Health Monitor") as demo:
    gr.Markdown("# 🫀 Multiscope Health Monitor - Telemetry Console\n*Author: Tejas Rohit Kharkar*")
    with gr.Row():
        bpm_box = gr.Textbox(label="Heart Rate", value="74 BPM")
        spo2_box = gr.Textbox(label="SpO2 Level", value="98.4 %")
        temp_box = gr.Textbox(label="Body Temp", value="36.6 °C")
    plot_ui = gr.Plot()
    stress_chk = gr.Checkbox(label="Simulate Stress Scenario", value=False)
    btn = gr.Button("Stream Live Telemetry Packet", variant="primary")
    btn.click(generate_telemetry, inputs=[stress_chk], outputs=[plot_ui, bpm_box, spo2_box, temp_box])

if __name__ == "__main__":
    demo.launch(server_name="0.0.0.0", server_port=7870, share=False)
